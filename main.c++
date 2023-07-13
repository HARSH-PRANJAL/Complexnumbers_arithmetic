#include "new_entries.c++"

int main()
{
    cout<<"     Welcome  !!"<<endl;
    cout<<"     This program performs different operations on complex number\n\n";
    cout<<"____________________Main menue _______________________________\n";
    cout<<"1. Perform Operations on new entries\n";
    cout<<"2. Open previous entries\n";
    cout<<"3. Exit\n\n";
    int op;
    cin>>op;
    switch (op)
    {
    case 1:
        new_entries();
        break;
    
    default:
        break;
    }
}