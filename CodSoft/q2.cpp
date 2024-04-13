#include <iostream>
using namespace std;

void display()
{
    cout << "Choose: " << endl;
    cout << " 1- Add \n 2- Subtract \n 3- Multiply \n 4- Divide \n " << endl;
}

float calculator(int ch, int a, int b)
{
    switch (ch)
    {
    case 1:
        return a + b;
        break;
    case 2:
        return a - b;
        break;
    case 3:
        return a * b;
        break;
    case 4:
        return a / b;
        break;
    default:
        cout << "Invalid choice\n";
        exit(0);
    }
}

int main()
{
    int ch;
    int n1, n2;
    float ans;
 
    cout << "Enter num1: ";
    cin >> n1;
    cout << "Enter num2: ";
    cin >> n2;

    display();
    cin >> ch;
    do
    {
        cout << "invalid choice. Re-enter: ";
        cin >> ch;
    } while ((ch < 0 || ch > 4));

    ans = calculator(ch, n1, n2);

    cout << "Ans: " << ans << endl;
    return 0;
}