#include <iostream>
#include <string>

using namespace std;

class record {
public:
    int result;
    void setNewRecord(int res) {
        result = res;
    }
    record(int res) {
        result = res;
    }
    virtual string getRecord() = 0;
};

class jumps : public record {
public:
    jumps() : record(0) {}
    jumps(int res) : record(res) {}
    string getRecord() override {
        return to_string(result) + "m";
    }
};

class weightlifting : public record {
public:
    weightlifting() : record(0) {}
    weightlifting(int res) : record(res) {}
    string getRecord() override {
        return to_string(result) + "kg";
    }
};

class running : public record {
public:
    running() : record(0) {}
    running(int res) : record(res) {}
    string getRecord() override {
        return to_string(result) + "m/s";
    }
};

int main() {

    record* a[3];

    string rec;
    int x = 0;

    cout << "Enter record for jumps: ";
    getline(cin, rec);
    for (auto now : rec) {
        if (!(now >= '0' && now <= '9')) {
            cout << "Enter correct record!";
            return 0;
        }
    }
    x = stoi(rec);
    a[0] = new jumps(x);

    cout << "Enter record for weightlifting: ";
    getline(cin, rec);
    for (auto now : rec) {
        if (!(now >= '0' && now <= '9')) {
            cout << "Enter correct record!";
            return 0;
        }
    }
    x = stoi(rec);
    a[1] = new weightlifting(x);

    cout << "Enter record for running: ";
    getline(cin, rec);
    for (auto now : rec) {
        if (!(now >= '0' && now <= '9')) {
            cout << "Enter correct record!";
            return 0;
        }
    }
    x = stoi(rec);
    a[2] = new running(x);

    cout << "\n";

    cout << "for jumps record is: " << a[0]->getRecord() << "\n";
    cout << "for weightlifting record is: " << a[1]->getRecord() << "\n";
    cout << "for running record is: " << a[2]->getRecord() << "\n";

}
