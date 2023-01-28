#include <iostream>
#include <string>
#include <vector>
#include <memory>


using namespace std;

class Instrument {
    public:
        string bloombergTicker;
        string ricCode;
        string companyName;
        Instrument(){};
};

class Position {
    public:
        string trader;
        double quantity;
        Instrument* instrument;
        explicit Position(Instrument* instrument);
};

class PositionV2 {
    public: 
        string trader;
        double quantity;
        shared_ptr<Instrument> instrument;
        explicit PositionV2(shared_ptr<Instrument> instrument);
};

vector<Position> constructPositions();
vector<PositionV2> constructPositionsV2();

void testConstructPositions();
void testConstructPositionsV2();

int main() {
    testConstructPositions();
    testConstructPositionsV2();
    return 1;
}

Position::Position(Instrument* instrument):
    instrument( instrument ) {};

PositionV2::PositionV2(shared_ptr<Instrument> instrument):
    instrument( instrument ) {};

vector<Position> constructPositions() {
    vector<Position> positions;
    Instrument* instrument = new Instrument; // violate information hiding
    instrument->companyName = "Google";
    instrument->bloombergTicker = "GOOG US Equity";
    instrument->ricCode = "GOOG.OQ";

    Position p1(instrument);
    p1.trader = "Han";
    p1.quantity = 100.0;
    positions.push_back(p1);

    Position p2(instrument);
    p2.trader = "Leo";
    p2.quantity = 200.0;
    positions.push_back(p2);

    return positions;
};

vector<PositionV2> constructPositionsV2() {
    vector<PositionV2> positions;
    shared_ptr<Instrument> instrument = make_shared<Instrument>(); // violate information hiding
    instrument->companyName = "Google";
    instrument->bloombergTicker = "GOOG US Equity";
    instrument->ricCode = "GOOG.OQ";

    PositionV2 p1(instrument);
    p1.trader = "Han";
    p1.quantity = 100.0;
    positions.push_back(p1);

    PositionV2 p2(instrument);
    p2.trader = "Leo";
    p2.quantity = 200.0;
    positions.push_back(p2);

    return positions;
}


void testConstructPositions() {
    vector<Position> positions = constructPositions();
    int n = positions.size();
    for (int i = 0 ; i < n; i++){
        cout << "Position [" << i << "]" <<"\n";
        Position& p = positions[i];
        cout << "Trader: " << p.trader << "\n";
        cout << "Quantity: " << p.quantity << "\n";
        cout << "Instrument: " ;
        cout << p.instrument->companyName << "\n";
        cout << "\n";
    }
    delete positions[0].instrument;
}

void testConstructPositionsV2() {
    vector<PositionV2> positions = constructPositionsV2();
    int n = positions.size();
    for (int i = 0 ; i < n; i++){
        cout << "Position [" << i << "]" <<"\n";
        PositionV2& p = positions[i];
        cout << "Trader: " << p.trader << "\n";
        cout << "Quantity: " << p.quantity << "\n";
        cout << "Instrument: " ;
        cout << p.instrument->companyName << "\n";
        cout << "\n";
    }
}
