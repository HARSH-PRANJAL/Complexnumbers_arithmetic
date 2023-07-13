#include "Cmplx_class_function.c++"

int main();            // declaration of main function
void clr_garbage();    // to delete the objects and sny other dynamic memory if present
void create_objects(); // function to create and initiate new objects
void operations();
Cmplx_number *obj; // global scope for dynamic objects

void new_entries() // menue function
{
    cout << "___________________New Entries Menue__________________________\n";
a:
    cout << endl;
    cout << "1. To enter new complex number\n"
         << "2. To perform Operations\n"
         << "3. Display all previous Operations and Answers\n"
         << "4. Exit\n\n";
    int op;
    cin >> op;
    switch (op)
    {
    case 1:
        create_objects();
        break;
    case 2:
        operations();
        break;
    case 3:
        display_stack();
        break;
    case 4:
        clr_garbage();
        main();
        break;
    }
    cout<<endl;
    goto a;
}

void create_objects()
{
    cout << "How many complex numbers do you want  -->  ";
    int num_objects;
    cin >> num_objects;
    obj = new Cmplx_number[num_objects]; // dynamically create objects as per required by the user
    for (int i = 0; i < num_objects; i++)
    {
        cin >> obj[i];
    }
    cout << endl
         << "Complex number entered by users are :-" << endl;

    for (int i = 1; i <= num_objects; i++)
    {
        cout << i << ". " << obj[i - 1] << endl;
    }
}

void operations()
{
    Cmplx_number temp, t1, t2;
a:
    cout << endl;
    cout << "Enter the operations to perform (one at a time):-" << endl
         << "Ex:- C1 + K {were K is another complex number or a constant}\n"
         << "Ex:- X + K {were X is the previous result}\n"
         << "Enter //cd.. to exit\n\n";
    string s;
    fflush(stdin);
    getline(cin, s);  // taking string for operation
    if (s[0] == '/') // exit to menue when operations are done envoked by user
    {
        s.clear();
        return;
    }

    char op;
    int b = -1;

    // extracting first opperand
    try
    {
        if (s[0] == 'C') // C1 + K
        {
            t1 = obj[s[1] - 49];
            op = s[3];
        }
        else // X + K
        {
            t1 = return_object();
            op = s[2];
        }
    }
    catch (exception e)
    {
        cout << "Eror :  Please enter the opperands as shown in example";
        goto a;
    }

    try
    {
        if (s[5] == 'C')
            t2 = obj[s[6] - 49];
        else
        {
            if (s[4] == 'C')
                t2 = obj[s[5] - 49];
            else
            {
                if (s[0] == 'X')
                    s.erase(0, 4);
                else
                    s.erase(0, 5);

                b = stoi(s);
            }
        }
    }
    catch (exception e)
    {
        cout << "Eror :  Please enter the opperands as shown in example";
        goto a;
    }
    cout << t1;
    cout << endl
         << t2;
    cout << endl
         << b;

    switch (op)
    {
    case '+':
    {
        if (s[5] == 'C' || s[4] == 'C')
            temp = t1 + t2;
        else
            temp = t1 + b;
    }
    break;
    case '-':
    {
        if (s[5] == 'C' || s[4] == 'C')
            temp = t1 - t2;
        else
            temp = t1 - b;
    }
    break;
    case '*':
    {
        if (s[5] == 'C' || s[4] == 'C')
            temp = t1 * t2;
        else
            temp = t1 * b;
    }
    break;
    case '/':
    {
        if (s[5] == 'C' || s[4] == 'C')
            temp = t1 / t2;
        else
            temp = t1 / b;
    }
    break;
    }
    cout << endl
         << "Result     " << temp << endl;
    insert(op, temp);
    goto a;
}

void clr_garbage()
{
    delete[] obj;
}