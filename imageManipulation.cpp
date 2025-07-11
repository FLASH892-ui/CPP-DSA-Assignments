/* Device a data structure (say Graphic) to represent an image data. And also define the following operations ->
    1) ScaleUp: To magnify the image by certain percent
    2) ScaleDown: To reduce the image by certain percent
    3) Rotate: To rotate the image either clockwise or anticlockwise by a certain angle(now only available : 90 deg,180 deg,270 deg
*/
#include <iostream>
#include <iomanip>
using namespace std;
void scaleUp(int arr[][5],int r,int c,int p){
    double scale = p/100.0;
    for (int i=0;i<r; i++){
        for (int j=0;j<c;j++){
            double result = arr[i][j] = arr[i][j] + arr[i][j] * scale;
            cout << fixed << setprecision(2) << result << " ";
        }
        cout << endl;
    }
}
void scaleDown(int arr[][5],int r,int c,int p){
    double scale = p/100.0;
    for (int i=0;i<r; i++){
        for (int j=0;j<c;j++){
            double result = arr[i][j] = arr[i][j] - arr[i][j]* scale;
            cout << fixed << setprecision(2) << result << " ";
        }
        cout << endl;
    }
}
void rotation(int arr[][5],int r,int c,int deg){
    int rotatedArr[5][5];
    if(deg ==90){
        for (int i=0;i<r; i++){
          for (int j=0;j<c;j++){
            rotatedArr[j][r-1-i] = arr[i][j];
          }
        }
        for (int i=0; i<r; i++){
            for (int j=0;j<c;j++){
                cout << rotatedArr[i][j] << " ";
            }
            cout << endl;
        }
    } else if(deg ==180){
        for (int i=0;i<r; i++){
          for (int j=0;j<c;j++){
            rotatedArr[c-1-j][r-1-i] = arr[i][j];
          }
        }
        for (int i=0;i<r; i++){
          for (int j=0;j<c;j++){
            cout << rotatedArr[i][j] << " ";
          }
          cout << endl;
        }
    } else if(deg ==270){
        for (int i=0;i<r; i++){
          for (int j=0;j<c;j++){
            rotatedArr[c-1-j][i] = arr[i][j];
          }
        }
        for (int i=0;i<r; i++){
          for (int j=0;j<c;j++){
            cout << rotatedArr[i][j] << " ";
          }
          cout << endl;
        }
    } else{
        for (int i=0;i<r; i++){
          for (int j=0;j<c;j++){
            cout << arr[i][j] << " ";
          }
          cout << endl;
        } 
    }
}
int main() {
    std::cout << "Bsic Scale & Rotate..\n";
    int row, col,percentage,rotate, num;
    int arr[5][5];
    
    cout << "Enter the row & column: ";
    cin >> row >> col;
    cout << "Enter the elements: ";
    for (int i=0;i<row; i++){
        for (int j=0;j<col;j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<row; i++){
        for (int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "What do you want to to do?" << endl;
    cout << "Scale up -> press 1" << endl;
    cout << "Scale down -> press 2" << endl;
    cout << "Rotate -> press 3" << endl;
    cin >> num;
    switch (num){
        case 1:
            cout << "Enter the scale up percentage: ";
            cin >> percentage;
            cout << endl;
            scaleUp(arr,row,col,percentage);
            break;
        case 2:
            cout << "Enter the scale down percentage: ";
            cin >> percentage;
            cout << endl;
            scaleDown(arr,row,col,percentage);
            break; 
        case 3:
            cout << "Enter the degree to rotate: ";
            cin >> rotate;
            cout << endl;
            rotation(arr,row,col,rotate);
            break;    
    }

    return 0;
}
