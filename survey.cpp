// File: survey.cpp
// Author: Po-Ying Fu
// cs102 Online
// Date: Nov 25, 2019
// Description: Final project

#include "WebApps.h"
#include "FileApps.h"

WebApps wo;
FileApps fo("survey.txt");	//fo for file object
void build_form();
void save_data_line(string);
string prepare_vote(int);
void display_result(string []);
int *create_int_array(string []);

int main()
{
	const int cnt = wo.get_cnt();
	if (cnt != 0) {

		build_form();

		cout << "debug with cnt != 0<br>" << endl;
		
		//call function to prepare vote 
		string data_line = prepare_vote(cnt);
		cout << "debug with data_line: " << data_line << "<br>" << endl;
		
		//save_data_line() appends the vote to the end of survey.txt
		fo.save_data_line(data_line);

		//read_data() opens survey.txt and populates array data_array[]
		fo.read_data();
		cout << "debug past read_data()<br>" << endl;

		//array data_array[] is now ours (contains all of the votes as strings
		string* data_array = fo.get_data_array();
		cout << "From main() debug with 1th element: " << data_array[0] << 
					"<br>" << endl;		
		// End of the need for FileApps.h under this if statement
		display_result(data_array);

	}else {
		build_form();
		fo.read_data();
		string* data_array = fo.get_data_array();
		display_result(data_array);
	}
	return 0;
}

//////functions//////
void	build_form()
{
	cout << "<html><head><title>Survey Vote</title></head>" <<
		"<body style=\"background-color:powderblue;\">\n" <<
		"<form action=\"survey.cgi\" method=\"GET\">\n" <<
		"	<h1>What languages do you speak?</h1><br>\n" <<
		"		<input name=\"vote\" value=\"en\" type=\"radio\"></td>\n" <<
		"		<label for=\"vote\">English</label><p>\n" <<
		"		<input name=\"vote\" value=\"cn\" type=\"radio\"></td>\n" <<
		"		<label for=\"vote\">Chinese</label><p>\n" <<
		"		<input name=\"vote\" value=\"ar\" type=\"radio\"></td>\n" <<
		"		<label for=\"vote\">Arabic</label><p>\n" <<
		"		<input name=\"vote\" value=\"sp\" type=\"radio\"></td>\n" <<
		"		<label for=\"vote\">Spanish</label><p>\n" <<
		"		<input name=\"vote\" value=\"fr\" type=\"radio\"></td>\n" <<
		"		<label for=\"vote\">French</label><p>\n" <<
		"		<input name=\"vote\" value=\"ru\" type=\"radio\"></td>\n" <<
		"		<label for=\"vote\">Russian</label><p>\n" <<
		"		<input name=\"vote\" value=\"other\" type=\"radio\"></td>\n" <<
		"		<label for=\"vote\">OTHERS</label><p>\n" <<
		"	<p><input type=\"submit\" value=\"Submit\">\n" <<
		"</form>\n" <<
		"<h3>You can choose multiple times, if you know more than one languages!</h3>" <<
		"</body>\n" << 
		"</html>\n";
}

string prepare_vote(int f_cnt)
{
		FIELDS *arr = wo.create_array(wo.get_cnt());
		string	vote = wo.param("vote", arr, wo.get_cnt());	

		cout << "debug with vote: " << vote << "< br>" << endl;
		
		return  vote + "|\n";

		//the new line character will put each vote 
		//on a new line in the file
		//ex of a concatenated vote: "y|\n"
		//Normally, this line of data would contain more fields, which would
		//commonly be separated by pipes, like:
		//"y|Fred|Flintstone|\n" - represents data for three fields.
		//Therefore, even if we use only one 
		//field this time, we remain consistent with the protocol.
}

int	*create_int_array(string f_data_array[])
{
	int	data_nbr;
	data_nbr = sizeof(f_data_array)/sizeof(f_data_array[0]);
	int	*int_array = new int [data_nbr];

	return int_array;
}

void display_result(string f_data_array[]) 
{	
	//function flow:
	// initialize a dynamic array (vote_tally_array) from function
	// create_int_array() (to be created under main(), not in the
	// class), which returns a pointer to an array 
	// with number of elements equal to the number of possible
	// (different) choices of votes:
	//	For example, Y or N will require a  vote_tally_array of 2
	//	elements 

	int	*vote_tally_array =  create_int_array(f_data_array);

	/* FOR TEST: */ <-- I'm HERE NOW!!!!!!!!!!!!! (write the data present table!)
	vote_tally_array[0] = 100;
	cout << "vote_tally_array[0] = " << vote_tally_array[0] << endl;

	// initialize vote_tally_array to 0’s in a loop
	// In another loop, increment vote_tally_array from f_data_array[]
	 	// Use something like this pseudocode::
		// if vote == "Y|" then vote_tally_array[0]++
		// else if vote == "N|" then vote_tally_array[1]++
	
	//print the results
}
