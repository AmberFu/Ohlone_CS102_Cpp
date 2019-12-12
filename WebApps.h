// File: WebApps.h
// Author: Po-Ying Fu
// cs102 Online
// Date: Dec 04, 2019
// Description: header file for survey.cpp

#ifndef WEBAPPS_H
#define WEBAPPS_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>       //for isalnum()
using namespace std;

struct FIELDS
{
        string name;
        string value;
};

const int cnt = 3;

class WebApps {
        public:                 //public access specifier.
                WebApps (){     //constructor

                        cout << "Content-type:text/html\n\n";   //get ready to print on browser
                        set_qs(getenv("QUERY_STRING"));                 //save string to private qs
                        set_cnt(how_many(get_qs()));
                }

                void set_qs(string f_getenv)
                {
                        qs = f_getenv;
                }

                void set_cnt(int f_how_many)
                {
                        cnt = f_how_many;
                }

                string get_qs()
                {
                        return qs;
                }

                int get_cnt()
                {
                        return cnt;
                }

                /////////////////////////////////////////////////////
                // how_many()
                // This will count and return how many = signs in the QUERYSTRING
                ////////////////////////////////////////////////////
                int how_many (string f_qs)
                {
                        //initialize variables
                        size_t start_pos = 0, pos;
                        int     n = 0;
                        while ((pos = qs.find("=", start_pos)) != string::npos)
                        {
                                n++;
                                start_pos = pos + 1;
                        }
                        return n;
                }


                ////////////////////////////////////////////////////
                //create_array
                // Creates a dynamic array
                ////////////////////////////////////////////////////

                FIELDS * create_array (int f_cnt)
                {
                        FIELDS * f_name_value_pairs = new FIELDS [f_cnt];
                        parse(qs, f_name_value_pairs);
                        return f_name_value_pairs;
                }

                /////////////////////////////////////////////
                // parse()
                // This will separate the name/value pairs found after the ? in the URL
                /////////////////////////////////////////////

                void parse (string f_qs, FIELDS f_name_value_pairs [])
		{
                        string name, value;

                        int start_pos = 0, pos;
                        for (int counter=0; counter < cnt; counter++) {
                                pos = f_qs.find("=", start_pos);        //was missing start_pos
                                name = f_qs.substr(start_pos, pos - start_pos);
                                f_name_value_pairs[counter].name = name;
                                start_pos = pos + 1;
                                pos = f_qs.find("&", start_pos);
                                if (pos == string::npos) {
                                        pos = f_qs.length();
                                }
                                value = f_qs.substr(start_pos, pos - start_pos);
                                f_name_value_pairs[counter].value = value;
                                start_pos = pos + 1;
                        }
                }

                /////////////////////////////////////////////
                // param()
                // Will receive the value for any given form field
                /////////////////////////////////////////////

                string param(string lookUp, FIELDS f_name_value_pairs [], int f_cnt)
                {
                        string f_value;

                        bool found = false;
                        for (int index = 0; index < f_cnt; index++)
                        {
                                if (lookUp.compare(f_name_value_pairs[index].name)==0){
                                        found = true;
                                        f_value = f_name_value_pairs[index].value;
                                }
                        }
                        if (found)
                                return f_value;
                        else
                                return "";
                }

        private:                                // private access specifier
                string qs;                      // holds the QUERY_STRING
                int cnt;                        // holds the number of fields found from the form
};

#endif

