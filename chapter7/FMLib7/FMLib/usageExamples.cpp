#include "usageExamples.h"

using namespace std;

///////////////////////////
//
//  THIS FILE CONTAINS MISCELLANOUS CODE
//  FROM THE LECTURE NOTES
//
///////////////////////////

void testWorking() {

///////////////////////////////////////
//
//   WORKING WITH VECTORS
//
///////////////////////////////////////

// create a vector
vector<double> myVector;

// add three elements to the end
myVector.push_back( 12.0 );
myVector.push_back( 13.0 );
myVector.push_back( 14.0 );

// read the first, second and third elements
cout << myVector[0] <<"\n";
cout << myVector[1] <<"\n";
cout << myVector[2] <<"\n";

// change the values of a vector
myVector[0] = 0.1;
myVector[1] = 0.2;
myVector[2] = 0.3;

// loop through a vector
int n = myVector.size();
for (int i=0; i<n; i++) {
   cout << myVector[i] <<"\n";
}

// Create a vector of length 10
// consisting entirely of 3.0's
vector<double> ten3s(10, 3.0 );

// Create a vector which is a copy of another
vector<double> copy( ten3s );
ASSERT( ten3s.size() == copy.size());

// replace it with myVector
copy = myVector;
ASSERT( myVector.size() == copy.size());

vector<int> threeInts({ 2, 3, 4 });

//////////////////////////////////
//  WORKING WITH FILES
/////////////////////////////////

// create an ofstream
ofstream out;

// choose where to write
out.open("myfile.txt");

out << "The first line\n";
out << "The second line\n";
out << "The third line\n";

// always close when you are finished
out.close();

//////////////////////////////
//
//  WORKING WITH STRINGS
//
/////////////////////////////

// Create a string
string s("Some text.");

// Write it to a stream
cout << s<< "\n";
cout << "Contains "
     << s.size() <<
     " characters \n";

// Change it
s.insert( 5, "more ");
cout << s <<"\n";

// Append to it with +
s += " Yet more text.";
cout << s <<"\n";

// Test equality
ASSERT( s=="Some more text. Yet more text.");

//////////////////////////////////
//
//   WORKING WITH STRINGSTREAMS
//
//////////////////////////////////
{

string s("");
for (int i=0; i<100; i++) {
    s+="blah ";
}
cout << s<<"\n";

stringstream ss;
for (int i=0; i<100; i++) {
    ss<<"blah ";
}
string s1 =ss.str();
cout << s1 <<"\n";

}

}

///////////////////////////
//
//  FUNCTION EXAMPLES
//
///////////////////////////

static
double sum( const vector<double>& v ) {
    double total = 0.0;
    int n = v.size();
    for (int i=0; i<n; i++) {
        total += v[i];
    }
    return total;
}

void writeHaiku( ostream& out ) {
   out << "The wren\n";
   out << "Earns his living\n";
   out << "Noiselessly.\n";
}

void testWriteHaiku() {
   // write a Haiku to cout
   writeHaiku( cout );
   // write a Haiku to a file
   ofstream out;
   out.open("haiku.txt");
   writeHaiku( out );
   out.close();
}


void writeCSVChartData( ostream& out,
        const vector<double>& x,
        const vector<double>& y ) {
    ASSERT( x.size()==y.size());
    int n = x.size();
    for (int i=0; i<n; i++) {
        out << x[i] <<","<<y[i] <<"\n";
    }
}
void writeCSVChart( const string& filename,
        const vector<double>& x,
        const vector<double>& y ) {
    ofstream out;
    out.open( filename.c_str() );
    writeCSVChartData( out, x, y );
    out.close();
}

void testSum() {
  vector<double> v;
  v.push_back(1.0);
  v.push_back(2.0);
  sum(v);
}

void testUsageExamples() {
    testWorking();
    testWriteHaiku();
    testSum();
}