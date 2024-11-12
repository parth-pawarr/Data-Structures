#include <iostream>
using namespace std;

struct EnvironmentalData {
    float temperature;
    float humidity;
    float pollution;
};

class EnvironmentManager {
private:
    EnvironmentalData data[100];
    int count;

public:
    EnvironmentManager() : count(0) {}

    void addData(float temperature, float humidity, float pollution);
    void displayData();
    void findMaxMin();
    void calculateAverage();
    void sortByPollution();
    void analyzeSafety();
    void analyzeHealthImpact();
};

void EnvironmentManager::addData(float temperature, float humidity, float pollution) {
    if (count < 100) {
        data[count].temperature = temperature;
        data[count].humidity = humidity;
        data[count].pollution = pollution;
        count++;
    } else {
        cout << "Data limit reached. Cannot add more data.\n";
    }
}

void EnvironmentManager::displayData() {
    if (count == 0) {
        cout << "No data available.\n";
        return;
    }

    cout << "\n******** Environmental Data ********\n";
    cout << "-------------------------------------\n";
    cout << "Temp (°C) | Humidity (%) | Pollution (AQI)\n";
    cout << "-------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << " " << data[i].temperature << "       | " 
             << data[i].humidity << "          | " 
             << data[i].pollution << "\n";
    }
    cout << "-------------------------------------\n";
}

void EnvironmentManager::findMaxMin() {
    if (count == 0) {
        cout << "No data available.\n";
        return;
    }

    float maxTemp = data[0].temperature;
    float minTemp = data[0].temperature;
    float maxHumidity = data[0].humidity;
    float minHumidity = data[0].humidity;
    float maxPollution = data[0].pollution;
    float minPollution = data[0].pollution;

    for (int i = 0; i < count; i++) {
        if (data[i].temperature > maxTemp) maxTemp = data[i].temperature;
        if (data[i].temperature < minTemp) minTemp = data[i].temperature;
        if (data[i].humidity > maxHumidity) maxHumidity = data[i].humidity;
        if (data[i].humidity < minHumidity) minHumidity = data[i].humidity;
        if (data[i].pollution > maxPollution) maxPollution = data[i].pollution;
        if (data[i].pollution < minPollution) minPollution = data[i].pollution;
    }

    cout << "\nMaximum Temperature: " << maxTemp << "°C\n";
    cout << "Minimum Temperature: " << minTemp << "°C\n";
    cout << "Maximum Humidity: " << maxHumidity << "%\n";
    cout << "Minimum Humidity: " << minHumidity << "%\n";
    cout << "Maximum Pollution: " << maxPollution << " AQI\n";
    cout << "Minimum Pollution: " << minPollution << " AQI\n";
}

void EnvironmentManager::calculateAverage() {
    if (count == 0) {
        cout << "No data available.\n";
        return;
    }

    float totalTemp = 0, totalHumidity = 0, totalPollution = 0;

    for (int i = 0; i < count; i++) {
        totalTemp += data[i].temperature;
        totalHumidity += data[i].humidity;
        totalPollution += data[i].pollution;
    }

    cout << "Average Temperature: " << totalTemp / count << "°C\n";
    cout << "Average Humidity: " << totalHumidity / count << "%\n";
    cout << "Average Pollution: " << totalPollution / count << " AQI\n";
}

void EnvironmentManager::sortByPollution() {
    if (count == 0) {
        cout << "No data available.\n";
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j].pollution > data[j + 1].pollution) {
                EnvironmentalData temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    cout << "Data sorted by Pollution Levels (AQI).\n";
    displayData();
}

void EnvironmentManager::analyzeSafety() {
    if (count == 0) {
        cout << "No data available.\n";
        return;
    }

    const float safeLowerLimit = 0;
    const float safeUpperLimit = 50;

    for (int i = 0; i < count; i++) {
        if (data[i].pollution < safeLowerLimit) {
            cout << "Pollution level " << data[i].pollution << " AQI is considered safe.\n";
        } else if (data[i].pollution <= safeUpperLimit) {
            cout << "Pollution level " << data[i].pollution << " AQI is moderate.\n";
        } else {
            cout << "Pollution level " << data[i].pollution << " AQI is unsafe!\n";
        }
    }
}

void EnvironmentManager::analyzeHealthImpact() {
    if (count == 0) {
        cout << "No data available.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        if (data[i].pollution > 100) {
            cout << "High pollution level (" << data[i].pollution << " AQI) can impact health!\n";
        } else {
            cout << "Pollution level (" << data[i].pollution << " AQI) is within safe limits.\n";
        }
    }
}

int main() {
    EnvironmentManager manager;
    int choice;

    do {
        cout << "\n******** Environment Management System ********\n";
        cout << "1. Add Environmental Data\n";
        cout << "2. Display Data\n";
        cout << "3. Find Max and Min Values\n";
        cout << "4. Calculate Average Values\n";
        cout << "5. Sort Data by Pollution Levels\n";
        cout << "6. Analyze Safety Levels\n";
        cout << "7. Analyze Health Impact\n";
        cout << "8. Exit\n";
        cout << "***********************************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                float temperature, humidity, pollution;
                cout << "Enter Temperature (°C): ";
                cin >> temperature;
                cout << "Enter Humidity (%): ";
                cin >> humidity;
                cout << "Enter Pollution Level (AQI): ";
                cin >> pollution;
                manager.addData(temperature, humidity, pollution);
                break;
            }
            case 2:
                manager.displayData();
                break;
            case 3:
                manager.findMaxMin();
                break;
            case 4:
                manager.calculateAverage();
                break;
            case 5:
                manager.sortByPollution();
                break;
            case 6:
                manager.analyzeSafety();
                break;
            case 7:
                manager.analyzeHealthImpact();
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
