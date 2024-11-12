#include<iostream>
using namespace std;

class SparseMatrix{
    private:
        int matrix[100][100];
        int sparse[100][3];
        int rows, cols;

    public:
        void acceptMatrix();
        void createSparseMatrix();
        void displaySparseMatrix();
        void displayOriginalMatrix();
        void simpleTranspose();
        void addition(SparseMatrix &matrix2);
};

int main(){
    SparseMatrix obj, matrix2;
    obj.acceptMatrix();
    obj.displayOriginalMatrix();
    obj.displaySparseMatrix();
    obj.simpleTranspose();
    obj.addition(matrix2);
}

void SparseMatrix::acceptMatrix(){
    cout<<"Enter the number of rows: ";
    cin>> rows;
    cout<<"Enter the number of coloumns: ";
    cin>>cols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<<"Enter element for element "<<i<<", "<<j<<": ";
            cin>>matrix[i][j];
        }
    }
    createSparseMatrix();
}

void SparseMatrix::createSparseMatrix(){
    int k = 1;
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            if(matrix[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k-1;

}

void SparseMatrix::displaySparseMatrix(){
    cout<<"\n\n";
    cout<<"SPARSE MATRIX \n\n";
    for(int i = 0; i <= sparse[0][2]; i++){
        for(int j = 0; j < 3; j++){
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }
}

void SparseMatrix::displayOriginalMatrix(){
    cout<<"\n\n";
    cout<<"ORIGINAL MATRIX \n\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void SparseMatrix::simpleTranspose() {
    int transpose[100][3];
    int k = 1; 

    
    for (int col = 0; col < sparse[0][1]; col++) {  
        for (int i = 1; i <= sparse[0][2]; i++) {  
            if (sparse[i][1] == col) {  
                transpose[k][0] = sparse[i][1];  
                transpose[k][1] = sparse[i][0];
                transpose[k][2] = sparse[i][2];
                k++;
            }
        }
    }
    
    
    transpose[0][0] = sparse[0][1];  
    transpose[0][1] = sparse[0][0];  
    transpose[0][2] = sparse[0][2];  

    
    cout << "\n\n";
    cout << "TRANSPOSED SPARSE MATRIX \n\n";
    for (int i = 0; i <= transpose[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

void SparseMatrix::addition(SparseMatrix &matrix2){
    int sum[100][3];
    int l1, l2;
    int i, j, k;
    i = j = k = 1;

    l1 = sparse[0][2];      //no of cols of matrix 1
    l2 = matrix2.sparse[0][2];      //no of cols of matrix 2

    while(i <= l1 && j <= l2){
        if(sparse[i][0] == matrix2.sparse[j][0]){       //if the row is same
            if(sparse[i][1] == matrix2.sparse[j][1]){   //if col also equal
                sum[k][0] = sparse[i][0];
                sum[k][1] = sparse[i][1];
                sum[k][2] = sparse[i][2] + matrix2.sparse[j][2] + 2;
                i++;
                j++;
                k++;
            }
            else{       //if col not equal
                if(sparse[i][1] < matrix2.sparse[j][1]){        //if 1st matrix's col is smaller than 2nd matrix's col
                    sum[k][0] = sparse[i][0];
                    sum[k][1] = sparse[i][1];
                    sum[k][2] = sparse[i][2];
                    k++;
                    i++;
                }
                else{       //if 2nd matrix's col is smaller
                    sum[k][0] = matrix2.sparse[j][0];
                    sum[k][1] = matrix2.sparse[j][1];
                    sum[k][2] = matrix2.sparse[j][2];
                    j++;
                    k++;
                }
            }
        }
        else{       //if rows are not equal
            if(sparse[i][0] < matrix2.sparse[j][0]){        //matrix1 row small
                sum[k][0] = matrix2.sparse[i][0];
                sum[k][1] = matrix2.sparse[i][1];
                sum[k][2] = matrix2.sparse[i][2];
                k++;
                i++;
            }
            else{       //matrix 2 row small
                sum[k][0] = matrix2.sparse[j][0];
                sum[k][1] = matrix2.sparse[j][1];
                sum[k][2] = matrix2.sparse[j][2];
                k++;
                j++;
            }
        }
    }
    while((j <= l2) && (i >= l1)){  //copy remaining elements of matrix2
        sum[k][0] = matrix2.sparse[j][0];
        sum[k][1] = matrix2.sparse[j][1];
        sum[k][2] = matrix2.sparse[j][2];
        k++;
        j++;
    }
    while((j >= l2) && (i <= l1)){      //copy remaining elements of matrix1
        sum[k][0] = sparse[i][0];
        sum[k][1] = sparse[i][1];
        sum[k][2] = sparse[i][2];
        k++;
        i++;
    }
    sum[0][0] = rows;
    sum[0][1] = cols;
    sum[0][2] = k - 1;

        cout<<"\n\n";
    cout<<"ADDITION MATRIX \n\n";
    for(int i = 0; i <= sum[0][2]; i++){
        for(int j = 0; j < 3; j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
}