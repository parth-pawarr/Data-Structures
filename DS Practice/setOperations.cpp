#include <iostream>
using namespace std;

class Set
{
public:
    int codingContest[10], projectCompetition[10], masterMind[10], paperPresentation[10];
    int codingSize, projectSize, masterSize, paperSize;

public:
    Set()
    {
        codingSize = projectSize = masterSize = paperSize = 0;
    }

    void addParticipants(int arr[], int &size);
    void displaySet(int arr[], int size);
    void setIntersection(int setA[], int sizeA, int setB[], int sizeB);
    void setUnion(int setA[], int sizeA, int setB[], int sizeB);
    void setDifference(int setA[], int sizeA, int setB[], int sizeB);
};

void Set::addParticipants(int arr[], int &size)
{
    int n;
    cout << "Enter the number of participants: ";
    cin >> n;
    if (size + n > 10)
    {
        cout << "Cannot add more participants. Max limit reached." << endl;
        return;
    }
    cout << "Enter the roll numbers of participants: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[size++];
    }
}

void Set::displaySet(int arr[], int size)
{
    cout << "Participants: ";
    if (size == 0)
    {
        cout << "none";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void Set::setIntersection(int setA[], int sizeA, int setB[], int sizeB)
{
    int intersectionSet[10];
    int intersectionSize = 0;
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            if (setA[i] == setB[j])
            {
                intersectionSet[intersectionSize++] = setA[i];
                break; 
            }
        }
    }
    displaySet(intersectionSet, intersectionSize);
}

void Set::setUnion(int setA[], int sizeA, int setB[], int sizeB)
{
    int unionSet[20]; // this is Enough space to hold both sets
    int unionSize = 0;

    // Adding elements of A
    for (int i = 0; i < sizeA; i++)
    {
        unionSet[unionSize++] = setA[i];
    }
    // Adding elements of B if not already present
    for (int i = 0; i < sizeB; i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < unionSize; j++)
        {
            if (setB[i] == unionSet[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            unionSet[unionSize++] = setB[i];
        }
    }
    displaySet(unionSet, unionSize);
}

void Set::setDifference(int setA[], int sizeA, int setB[], int sizeB)
{
    int setDifference[10];
    int differenceSize = 0;
    for (int i = 0; i < sizeA; i++)
    {
        bool isFound = false;
        for (int j = 0; j < sizeB; j++)
        {
            if (setA[i] == setB[j])
            {
                isFound = true;
                break;
            }
        }
        if (!isFound)
        {
            setDifference[differenceSize++] = setA[i];
        }
    }
    displaySet(setDifference, differenceSize);
}

int main()
{
    Set obj;
    while (true)
    {
        cout << "\n\n";
        cout << "1. Add participants in Coding Contest" << endl;
        cout << "2. Add participants in Project Competition" << endl;
        cout << "3. Add participants in Paper Presentation" << endl;
        cout << "4. Add participants in Master Mind" << endl;
        cout << "5. Find participants in Coding and Project Competition (Intersection)" << endl;
        cout << "6. Find participants in Coding or Project Competition (Union)" << endl;
        cout << "7. Find participants in Coding but not in Master Mind (Difference)" << endl;
        cout << "8. Display participants in all events" << endl;
        cout << "9. Exit" << endl;

        int ch;
        cout << "Enter your choice: ";
        cin >> ch; 
        switch (ch)
        {
        case 1:
            obj.addParticipants(obj.codingContest, obj.codingSize);
            break;
        case 2:
            obj.addParticipants(obj.projectCompetition, obj.projectSize);
            break;
        case 3:
            obj.addParticipants(obj.paperPresentation, obj.paperSize);
            break;
        case 4:
            obj.addParticipants(obj.masterMind, obj.masterSize);
            break;
        case 5:
            obj.setIntersection(obj.codingContest, obj.codingSize, obj.projectCompetition, obj.projectSize);
            break;
        case 6:
            obj.setUnion(obj.codingContest, obj.codingSize, obj.projectCompetition, obj.projectSize);
            break;
        case 7:
            obj.setDifference(obj.codingContest, obj.codingSize, obj.masterMind, obj.masterSize);
            break;
        case 8:
            cout << "Coding Contest: ";
            obj.displaySet(obj.codingContest, obj.codingSize);
            cout << "Project Competition: ";
            obj.displaySet(obj.projectCompetition, obj.projectSize);
            cout << "Master Mind: ";
            obj.displaySet(obj.masterMind, obj.masterSize);
            cout << "Paper Presentation: ";
            obj.displaySet(obj.paperPresentation, obj.paperSize);
            break;
        case 9:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
