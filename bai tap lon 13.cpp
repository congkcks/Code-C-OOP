#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

struct CallInfo {
    int nhCount;
    int lcCount;
    int xCount;
    int rxCount;
};

void calculateCost(const CallInfo& callInfo, double& totalCost,string callTime) {
    const double basePrice = 1100;
    const double nhCoefficient = 1;
    const double lcCoefficient = 2;
    const double xCoefficient = 3;
    const double rxCoefficient = 4;
    const double discountRate = 0.7;

    totalCost = basePrice * (callInfo.nhCount * nhCoefficient +
                             callInfo.lcCount * lcCoefficient +
                             callInfo.xCount * xCoefficient +
                             callInfo.rxCount * rxCoefficient);

    // Apply discount for calls between 23:00 and 05:00
    // and on weekends (Saturday and Sunday)
    // Here, I assume that the time is in the format "hh:mm"
    string startTime = "23:00";
    string endTime = "05:00";
    bool isWeekend = false; // You can implement the logic to check if it's a weekend

    if (isWeekend || (startTime <= callTime && callTime <= endTime)) {
        totalCost *= discountRate;
    }
}

int main() {
    map<string, string> customers;
    map<string, CallInfo> callInfo;
    string callTime;

    // Read customer information from khachhang.txt
    ifstream customerFile("khachhang.txt");
    if (customerFile.is_open()) {
        string line;
        while (getline(customerFile, line)) {
            stringstream ss(line);
            string name, phone;
            getline(ss, name, ';');
            getline(ss, phone);
            customers[phone] = name;
        }
        customerFile.close();
    } else {
        cout << "Failed to open khachhang.txt" << endl;
        return 1;
    }

    // Read call information from cuocgoi.txt
    ifstream callFile("cuocgoi.txt");
    if (callFile.is_open()) {
        string line;
        while (getline(callFile, line)) {
            stringstream ss(line);
            string phone, minutes, callTime, date, zone;
            getline(ss, phone, ';');
            getline(ss, minutes, ';');
            getline(ss, callTime, ';');
            getline(ss, date, ';');
            getline(ss, zone);

            CallInfo& info = callInfo[phone];
            if (zone == "NH") {
                info.nhCount++;
            } else if (zone == "LC") {
                info.lcCount++;
            } else if (zone == "X") {
                info.xCount++;
            } else if (zone == "RX") {
                info.rxCount++;
            }
        }
        callFile.close();
    } else {
        cout << "Failed to open cuocgoi.txt" << endl;
        return 1;
    }

    // Write the result to ketqua.txt
    ofstream resultFile("ketqua.txt");
    if (resultFile.is_open()) {
        for (const auto& entry : customers) {
            const string& phone = entry.first;
            const string& name = entry.second;
            const CallInfo& info = callInfo[phone];

            double totalCost = 0;
            calculateCost(info, totalCost,callTime);

            resultFile << name << "; " << phone << "; " << totalCost << "; "
                       << info.nhCount << "; " << info.lcCount << "; "
                       << info.xCount << "; " << info.rxCount << endl;
        }
        resultFile.close();
    } else {
        cout << "Failed to open ketqua.txt" << endl;
        return 1;
    }

    return 0;
}
