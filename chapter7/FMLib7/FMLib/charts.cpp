#include "charts.h"
#include "testing.h"

using namespace std;

/**
 *  Write the necessary junk for the top of the chart
 */
static void writeTopBoilerPlateOfPieChart( ostream& out ) {
    out<<"<html>\n";
    out<<"<head>\n";
    out<<"<!--Load the AJAX API-->\n";
    out<<"<script type=\"text/javascript\"";
    out<<"src=\"https://www.google.com/jsapi\">";
    out<<"</script>\n";
    out<<"<script type=\"text/javascript\">\n";
    out<<"google.load('visualization', '1.0',";
    out<<" {'packages':['corechart']});\n";
    out<<"google.setOnLoadCallback(drawChart);\n";
    out<<"function drawChart() {\n";
    out<<"var data=new google.visualization.DataTable();";
    out<<"\n";
    out<<"data.addColumn('string', 'Label');\n";
    out<<"data.addColumn('number', 'Value');\n";
}
/**
 *  Write the intesting bit of the Pie Chart
 */
static void writeDataOfPieChart( ostream& out,
                   const vector<string>& labels,
                   const vector<double>& values) {
    out<< "data.addRows([\n";
    int nLabels = labels.size();
    for (int i=0; i<nLabels; i++) {
        string label = labels[i];
        double value = values[i];
        out<<"['"<<label<<"', "<<value<<"]";
        if (i!=nLabels-1) {
            out<<",";
        }
        out<<"\n";
    }
    out<<"]);\n";
}

/**
 *  Write the boring bit at the bottom of a pie chart
 */
static void writeBottomBoilerPlateOfPieChart(
		ostream & out ) {
    out<<"var options = {'title':'A Pie Chart',\n";
    out<<"'width':400,\n";
    out<<"'height':300\n";
    out<<"};\n";
    out<<"var chart = new google.visualization.PieChart(";
    out<<"document.getElementById('chart_div'));\n";
    out<<"chart.draw(data, options);\n";
    out<<"}\n";
    out<<"</script>\n";
    out<<"</head>\n";
    out<<"<body>\n";
    out<<"<div id='chart_div'>\n";
    out<<"</body>\n";
    out<<"</html>";
}
/**
 *   Write a pie chart
 */
void pieChart( const string& file,
               const vector<string>& labels,
               const vector<double>& values ) {
    ofstream out;
    out.open(file.c_str());
    writeTopBoilerPlateOfPieChart(out);
    writeDataOfPieChart( out, labels, values );
    writeBottomBoilerPlateOfPieChart( out );
    out.close();
}

////////////////////////
//
//   TEMPORARY FUNCTIONS THAT OCCURRED WHILE
///  DEVELOPING THE SOLUTION, NORMALLY I'D DELETE THESE
//   AT THE END OF DEVELOPMENT
//
////////////////////////

/**
 *   While developing the code we wrote these (temporary) functions. We'd
 *   delete this from our final library.
 */
static void writeFixedPieChartData( ostream& out) {
    out<<"data.addRows([\n";
    out<<"['Bananas', 100],\n";
    out<<"['Apples', 200],\n";
    out<<"['Kumquats', 150]\n";
    out<<"]);\n";
}

static void testFixedPieChart() {
    ofstream out;
    out.open("FixedPieChart.html");
    writeTopBoilerPlateOfPieChart(out);
    writeFixedPieChartData( out );
    writeBottomBoilerPlateOfPieChart( out );
    out.close();
}



///////////////////////////////////////////
//
//   Tests for charts
//
///////////////////////////////////////////


static void testPieChart() {
    // this test is unsatisfactory in that it requires manual
    // checking, you'll have to hunt for the file it generates and then
    // view it in a web browser
    vector<string> labels(10);
    vector<double> vals(10);
    for (int i=0; i<10; i++) {
        stringstream ss;
        ss<<"A Label "<<i;
        labels[i] =ss.str();
        vals[i]=(double)i;
    }
    pieChart( "myPieChart.html",
              labels,
              vals );
}

static void testPieChartData() {
    // this test automates the checking
    stringstream out;
    vector<string> labels(3);
    vector<double> vals(3);
    for (int i=0; i<3; i++) {
        stringstream ss;
        ss<<"A Label "<<i;
        labels[i] =ss.str();
        INFO( labels[i] );
        vals[i]=(double)i;
    }
    writeDataOfPieChart( out,
              labels,
              vals );
    string asString = out.str();

    stringstream expected;
    expected<<"data.addRows([\n";
    expected<<"['A Label 0', 0],\n";
    expected<<"['A Label 1', 1],\n";
    expected<<"['A Label 2', 2]\n";
    expected<<"]);\n";
    string expectedStr = expected.str();
    ASSERT( asString==expectedStr );
}


void testCharts() {
    TEST( testFixedPieChart );
    TEST( testPieChart );
    TEST( testPieChartData );
}