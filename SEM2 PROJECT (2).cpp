#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>
using namespace std;
void setCursorPosition(int x, int y);
class Data{
	public:
		int freespace;
		string disk[20];
	Data()
	{
		freespace=20;
		for(int i=0;i<20;i++)
		{
			disk[i]="";
		}
	}
	void display()
{
    for(int i=0;i<20;i++)
    {
        if(disk[i].empty())
        {
            cout<<"Block "<<i<<" = Empty"<<endl;
        }
        else
        {
            cout<<"Block "<<i<<" = Occupied ("<<disk[i]<<")"<<endl;
        }
    }
}
bool create(int size, string fileName)
{
    int counter = 0;
    if(size > 0 && size <= freespace)
    {
        for(int i = 0; i < 20; i++)
        {
            if(disk[i].empty())
            {
                disk[i] = fileName;
                counter++;
                freespace--;
                if(counter == size)
                {
                    break;
                }
            }
        }
        return true;
    }
    else
{
    setCursorPosition(35, 19);
    cout << "Sorry File Not Allocated";
    return false;
}
}
};
class File
{
public:
    string file_name;
    int file_size;
    bool operator==(const File &other)
    {
        return file_name == other.file_name;
    }
};
class ActiveFile : public File
{
public:
    void search(string name)
{
    if(file_name == name)
    {
        setCursorPosition(35, 15);
        cout << "File Found!";
        setCursorPosition(35, 17);
        cout << "File Name: " << file_name;
        setCursorPosition(35, 19);
        cout << "File Size: " << file_size;
    }
}
void search(string name, int size)
{
    if(file_name == name && file_size == size)
    {
        setCursorPosition(35, 15);
        cout << "File Found!";
        setCursorPosition(35, 17);
        cout << "File Name: " << file_name;
        setCursorPosition(35, 19);
        cout << "File Size: " << file_size;
    }
}
    void deleteFile(Data &d)
    {
        for(int i = 0; i < 20; i++)
        {
            if(d.disk[i] == file_name)
            {
                d.disk[i] = "";
                d.freespace++;
            }
        }
    }
};
class DeletedFile : public File
{
public:
   void recover(Data &d)
{
    if(file_size <= d.freespace)
    {
        int size = file_size;
        for(int i = 0; i < 20; i++)
        {
            if(d.disk[i].empty())
            {
                d.disk[i] = file_name;
                d.freespace--;
                size--;

                if(size == 0)
                {
                    break;
                }
            }
        }
    }
    else
    {
        cout << "Not enough disk space to recover file." << endl;
    }
}
};
void saveData(ActiveFile f[], int fileCount)
{
    ofstream out("C://simulator.txt");
    for(int i = 0; i < fileCount; i++)
    {
        out << f[i].file_name << " "<< f[i].file_size << endl;
    }
    out.close();
}
void loadData(ActiveFile f[], int &fileCount, Data &d, int &i)
{
    ifstream in("simulator.txt");
    if(!in)
    {
        cout << "No saved data found." << endl;
        return;
    }
    while(in >> f[fileCount].file_name>> f[fileCount].file_size)
    {
       d.create(f[fileCount].file_size, f[fileCount].file_name);
       fileCount++;
       i++;
    }
    in.close();
    cout << "Data loaded successfully!" << endl;
}
void setCursorPosition(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void drawBackground()
{
    setColor(8); // Top background
    setCursorPosition(8, 30);
    cout << "10 01 00 11 01 10 00 01 11 10";
    setCursorPosition(75, 30);
    cout << "01 11 10 00 01 10 11 00 01";
    setCursorPosition(4, 8); // Left digital pattern
    cout << "01 01 10 11 00";
    setCursorPosition(4, 9);
    cout << "10 00 11 01 10";
    setCursorPosition(4, 10);
    cout << "00 11 01 10 01";
    setCursorPosition(103, 8); // Right digital pattern
    cout << "10 01 11 00 10";
    setCursorPosition(103, 9);
    cout << "01 10 00 11 01";
    setCursorPosition(103, 10);
    cout << "11 00 10 01 10";
    setCursorPosition(8, 32);   // Bottom background
    cout << "10 01 00 11 01 10 00 01 11 10";
    setCursorPosition(75, 32);
    cout << "01 11 10 00 01 10 11 00 01";
    setCursorPosition(103, 25);// Recovery indicator
    cout << "<->";
    setCursorPosition(101, 26);
    cout << "RECOVERY";
}
void drawCaseTitle(string title)
{
    setColor(11);
    setCursorPosition(35, 13);
    cout << "+------------------------------------------------+";
    setCursorPosition(35, 14);
    cout << "|";
    setCursorPosition(36, 14);
    int spaces = (48 - title.length()) / 2;
    for(int i = 0; i < spaces; i++)
    {
        cout << " ";
    }
    cout << title;
    setCursorPosition(82, 14);
    cout << "|";
    setCursorPosition(35, 15);
    cout << "+------------------------------------------------+";
    setColor(15);
}
int main()
{
	system("mode con cols=120 lines=35");
	char choice;
	int numberOfFiles;
	int fileCount = 0;
	cout<<"Virtual Data Recovery Simulator "<<endl;
	Data d;
	ActiveFile f[10];
	DeletedFile deleted[10];
    int deletedCount = 0;
    int i = 0;
    loadData(f, fileCount, d, i);
    int menuChoice;
do
{
	system("cls");
drawBackground();// ================= BACKGROUND =================
setColor(11);// ================= MAIN MENU =================
setCursorPosition(30, 3);
cout << "+--------------------------------------------------------------------+";
setCursorPosition(30, 4);
cout << "|                                                                    |";
setCursorPosition(30, 5);
cout << "|              VIRTUAL DATA RECOVERY SIMULATOR                       |";
setCursorPosition(30, 6);
cout << "|                                                                    |";
setCursorPosition(30, 7);
cout << "+--------------------------------------------------------------------+";
setColor(15);
setCursorPosition(30, 8);
cout << "|                                                                    |";
setCursorPosition(30, 9);
cout << "|                  1. Create File                                    |";
setCursorPosition(30, 10);
cout << "|                                                                    |";
setCursorPosition(30, 11);
cout << "|                  2. Search File                                    |";
setCursorPosition(30, 12);
cout << "|                                                                    |";
setCursorPosition(30, 13);
cout << "|                  3. Delete File                                    |";
setCursorPosition(30, 14);
cout << "|                                                                    |";
setCursorPosition(30, 15);
cout << "|                  4. Recover File                                   |";
setCursorPosition(30, 16);
cout << "|                                                                    |";
setCursorPosition(30, 17);
cout << "|                  5. Display Files                                  |";
setCursorPosition(30, 18);
cout << "|                                                                    |";
setCursorPosition(30, 19);
cout << "|                  6. Check Free Space                               |";
setCursorPosition(30, 20);
cout << "|                                                                    |";
setCursorPosition(30, 21);
cout << "|                  7. Exit                                           |";
setCursorPosition(30, 22);
cout << "|                                                                    |";
setCursorPosition(30, 23);
cout << "+--------------------------------------------------------------------+";
setColor(14);
setCursorPosition(30, 26);
cout << "Enter your choice: ";
setColor(15);
    while(!(cin >> menuChoice))
{
    cin.clear();
    cin.ignore(1000, '\n');
    setCursorPosition(30, 28);
    cout << "Invalid choice! Please enter a number from 1 to 7: ";
}
    switch(menuChoice)
    {
     case 1://////////////////////////1
{
    system("cls");
    drawBackground();
    // CREATE FILE title
setColor(11);
setCursorPosition(35, 8);
cout << "+------------------------------------------------+";
setCursorPosition(35, 9);
cout << "|";
setCursorPosition(36, 9);
int spaces = (48 - string("CREATE FILE").length()) / 2;
for(int i = 0; i < spaces; i++)
{
    cout << " ";
}
cout << "CREATE FILE";
setCursorPosition(82, 9);
cout << "|";
setCursorPosition(35, 10);
cout << "+------------------------------------------------+";
setColor(15);
// Question
setCursorPosition(35, 12);
cout << "How many files do you want to create? ";
setColor(15);
string fileCountInput = "";
while(true)
{
    char key = _getch();
    if(key == 27)       // ESC
    {
        break;
    }
    if(key == 13)       // ENTER
    {
        break;
    }
    if(key == 8)        // BACKSPACE
    {
        if(!fileCountInput.empty())
        {
            fileCountInput.pop_back();
            cout << "\b \b";
        }
    }
    else if(key >= '0' && key <= '9')
    {
        fileCountInput += key;
        cout << key;
    }
}
if(fileCountInput.empty())
{
    break;
}
try
{
    numberOfFiles = stoi(fileCountInput);
    if(numberOfFiles <= 0)
    {
       setCursorPosition(35, 17);
cout << "Please enter a positive number.";
        break;
    }
}
catch(const exception &e)
{
    cout << "\nInvalid input!" << endl;
    break;
}
    if(numberOfFiles > 10 - i)
    {
        setCursorPosition(35, 17);
cout << "You can create only " << 10 - i<< " more files.";
        break;
    }
        bool backFromCreate = false;
bool fileCreated = false;
for(int j = 0; j < numberOfFiles; j++)
{
        if(d.freespace == 0)
        {
          setCursorPosition(35, 22);
          cout << "Memory Full! No free space available.";
          setCursorPosition(35, 24);
          cout << "Press any key to continue...";
          _getch();
          break;
        }
        setCursorPosition(35, 15);// Clear previous input and error message
        cout << "                                                            ";
        bool firstKey = true;
        setCursorPosition(35, 15);
        cout << "Enter File Name: ";
        setCursorPosition(51, 15);
        f[i].file_name = "";
        bool back = false;
while(true)
{
    char key = _getch();

    if(key == 27)       // ESC
    {
        back = true;
        break;
    }
    if(key == 13)       // ENTER
    {
        break;
    }
    if(key == 8)        // BACKSPACE
    {
        if(!f[i].file_name.empty())
        {
            f[i].file_name.pop_back();
            cout << "\b \b";
        }
    }
   else
{
    if(firstKey)
    {
        setCursorPosition(35, 22);
        cout << "                                                            ";
        setCursorPosition(51, 15);
firstKey = false;
    }
    f[i].file_name += key;
    cout << key;
}
}
if(back)
{
    backFromCreate = true;
    break;
}
    if(f[i].file_name.size() < 5 ||f[i].file_name[f[i].file_name.size() - 4] != '.' ||f[i].file_name.substr(f[i].file_name.size() - 3) != "txt")
{
   setCursorPosition(35, 19);
cout << "Invalid file name! Use the format name.txt";
    j--;
    continue;
}
bool duplicate = false;
for(int k = 0; k < fileCount; k++)
{
    if(f[k] == f[i])
    {
        duplicate = true;
        break;
    }
}
if(duplicate)
{
    setCursorPosition(35, 19);
    cout << "File name already exists!";
    j--;
    continue;
}
setCursorPosition(35, 17);
cout << "Enter File Size: ";
string sizeInput = "";
bool backSize = false;
while(true)
{
    char key = _getch();
    if(key == 27)       // ESC
    {
        backSize = true;
        break;
    }
    if(key == 13)       // ENTER
    {
        break;
    }
    if(key == 8)        // BACKSPACE
    {
        if(!sizeInput.empty())
        {
            sizeInput.pop_back();
            cout << "\b \b";
        }
    }
    else if(key >= '0' && key <= '9')
    {
        sizeInput += key;
        cout << key;
    }
}
if(backSize)
{
    backFromCreate = true;
    break;
}
if(sizeInput.empty())
{
   setCursorPosition(35, 21);
cout << "Invalid file size!";
    j--;
    continue;
}
try
{
    f[i].file_size = stoi(sizeInput);

    if(f[i].file_size <= 0)
    {
        setCursorPosition(35, 21);
        cout << "File size must be greater than 0!";
        j--;
        continue;
    }
}
            catch(const exception &e)
           {
              setCursorPosition(35, 19);
              cout << "Invalid file size!";
              j--;
              continue;
           }
        if(d.create(f[i].file_size, f[i].file_name))
           { 
             fileCount++;
             i++;
             fileCreated = true;
           }
    }
if(backFromCreate)
{
    if(fileCreated)
    {
        saveData(f, fileCount);
    }
    break;
}
if(fileCreated)
{
    saveData(f, fileCount);
    setCursorPosition(35, 21);
cout << "File allocated successfully!";
}
setCursorPosition(35, 24);
cout << "Press any key to return to Main Menu...";
_getch();
break;
}
   case 2:///////////////////////////////2
{
    system("cls");
    drawBackground();
    setColor(11);
    setCursorPosition(35, 8);
    cout << "+------------------------------------------------+";
    setCursorPosition(35, 9);
    cout << "|";
    setCursorPosition(36, 9);
    int spaces = (48 - string("SEARCH FILE").length()) / 2;
    for(int i = 0; i < spaces; i++)
    {
        cout << " ";
    }
    cout << "SEARCH FILE";
    setCursorPosition(82, 9);
    cout << "|";
    setCursorPosition(35, 10);
    cout << "+------------------------------------------------+";
    setColor(15);
    while(true)
    {
        string searchName;
        setCursorPosition(35, 12);// Clear previous input line
        cout << "                                                            ";
        setCursorPosition(35, 12);
        cout << "Enter File Name: ";
        searchName = "";
        while(true)
        {
            char key = _getch();
            if(key == 27)   // ESC
            {
                break;
            }
            if(key == 13)   // ENTER
            {
                break;
            }
            if(key == 8)    // BACKSPACE
            {
                if(!searchName.empty())
                {
                    searchName.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                searchName += key;
                cout << key;
            }
        }
        if(searchName.empty()) // ESC
        {
            break;
        }
        bool found = false;
        for(int j = 0; j < fileCount; j++)
        {
            if(f[j].file_name == searchName)
            {
                setCursorPosition(35, 15);// Clear previous error messages
                cout << "                                                            ";
                setCursorPosition(35, 17);
                cout << "                                                            ";
                setCursorPosition(35, 19);
                cout << "                                                            ";                                                      
                f[j].search(searchName);// Display search result
                found = true;
                break;
            }
        }
        if(found)
        {
            setCursorPosition(35, 21);
            cout << "Press any key to continue...";
            _getch();

            break;
        }
        else
        {
            setCursorPosition(35, 17);
            cout << "File Not Found!";
            setCursorPosition(35, 19);
            cout << "Please enter the file name again.";
        }
    }

    break;
}
        case 3://///////////////////////////////////////3
{
    system("cls");
    drawBackground();
    setColor(11);  // DELETE FILE title
    setCursorPosition(35, 8);
    cout << "+------------------------------------------------+";
    setCursorPosition(35, 9);
    cout << "|";
    setCursorPosition(36, 9);
    int spaces = (48 - string("DELETE FILE").length()) / 2;
    for(int i = 0; i < spaces; i++)
    {
        cout << " ";
    }
    cout << "DELETE FILE";
    setCursorPosition(82, 9);
    cout << "|";
    setCursorPosition(35, 10);
    cout << "+------------------------------------------------+";
    setColor(15);
    while(true)
    {
        string deleteName;
        setCursorPosition(35, 12);// Clear input line
        cout << "                                                            ";
        setCursorPosition(35, 12);
        cout << "Enter File Name: ";
        setCursorPosition(35, 14);
        setColor(14);
        cout << "(Press ESC to go back)";
        setColor(15);
        setCursorPosition(51, 12);
        deleteName = "";
        bool firstKey = true;
        while(true)
        {
            char key = _getch();

            if(key == 27)   // ESC
            {
                break;
            }
            if(key == 13)   // ENTER
            {
                break;
            }
            if(key == 8)    // BACKSPACE
            {
                if(!deleteName.empty())
                {
                    deleteName.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                if(firstKey)
                {
                    setCursorPosition(35, 18);
                    cout << "                                                            ";
                    setCursorPosition(35, 20);
                    cout << "                                                            ";
                    setCursorPosition(51, 12);
                    firstKey = false;
                }
                deleteName += key;
                cout << key;
            }
        }
        if(deleteName.empty())// ESC 
        {
            break;
        }
        bool deleteFound = false;
        for(int j = 0; j < fileCount; j++)
        {
            if(f[j].file_name == deleteName)
            {
                deleted[deletedCount].file_name = f[j].file_name;
                deleted[deletedCount].file_size = f[j].file_size;
                deletedCount++;
                f[j].deleteFile(d);
                for(int k = j; k < fileCount - 1; k++)
                {
                    f[k] = f[k + 1];
                }
                fileCount--;
                i--;
                deleteFound = true;
                break;
            }
        }
        if(deleteFound)
        {
            saveData(f, fileCount);
            setCursorPosition(35, 18);
            cout << "File deleted successfully!";
            setCursorPosition(35, 20);
            cout << "Press any key to continue...";
            _getch();
            break;
        }
        else
        {
            setCursorPosition(35, 18);
            cout << "File Not Found!";
            setCursorPosition(35, 20);
            cout << "Please enter the file name again.";
        }
    }

    break;
}
        case 4:////////////////////////////////////////////4
{
    system("cls");
    drawBackground();
    setColor(11);// RECOVER FILE title
    setCursorPosition(35, 8);
    cout << "+------------------------------------------------+";
    setCursorPosition(35, 9);
    cout << "|";
    setCursorPosition(36, 9);
    int spaces = (48 - string("RECOVER FILE").length()) / 2;
    for(int i = 0; i < spaces; i++)
    {
        cout << " ";
    }
    cout << "RECOVER FILE";
    setCursorPosition(82, 9);
    cout << "|";
    setCursorPosition(35, 10);
    cout << "+------------------------------------------------+";
    setColor(15);
    while(true)
    {
        string recoverName;

        // Clear previous filename
        setCursorPosition(51, 12);
        cout << "                              ";
        setCursorPosition(35, 12);
        cout << "Enter File Name: ";
        setCursorPosition(35, 14);
        setColor(14);
        cout << "(Press ESC to go back)";
        setColor(15);
        setCursorPosition(51, 12);
        recoverName = "";
        bool firstKey = true;
        while(true)
        {
            char key = _getch();

            if(key == 27)       // ESC
            {
                break;
            }
            if(key == 13)       // ENTER
            {
                break;
            }
            if(key == 8)        // BACKSPACE
            {
                if(!recoverName.empty())
                {
                    recoverName.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                if(firstKey)
                {
                    setCursorPosition(35, 18);
                    cout << "                                                            ";
                    setCursorPosition(35, 20);
                    cout << "                                                            ";
                    setCursorPosition(51, 12);
                    firstKey = false;
                }
                recoverName += key;
                cout << key;
            }
        }
        if(recoverName.empty())// ESC
        {
            break;
        }
        bool recoverFound = false;
        bool notEnoughSpace = false;
        for(int j = 0; j < deletedCount; j++)
        {
            if(deleted[j].file_name == recoverName)
            {
                if(deleted[j].file_size <= d.freespace)
                {
                    f[fileCount].file_name = deleted[j].file_name;
                    f[fileCount].file_size = deleted[j].file_size;
                    deleted[j].recover(d);
                    for(int k = j; k < deletedCount - 1; k++)
                    {
                        deleted[k] = deleted[k + 1];
                    }
                    deletedCount--;
                    fileCount++;
                    i++;
                    recoverFound = true;
                    saveData(f, fileCount);
                    setCursorPosition(35, 18);
                    cout << "File recovered successfully!";
                    setCursorPosition(35, 20);
                    cout << "Press any key to continue...";
                    _getch();
                    break;
                }
                else
                {
                    setCursorPosition(35, 18);
                    cout << "Not enough disk space to recover file.";
                    setCursorPosition(35, 20);
                    cout << "Please enter another file name.";
                    notEnoughSpace = true;
                    break;
                }
            }
        }
        if(recoverFound)
        {
            break;
        }
        else if(notEnoughSpace)
        {
            continue;
        }
        else
        {
            setCursorPosition(35, 18);
            cout << "Deleted File Not Found!";
            setCursorPosition(35, 20);
            cout << "Please enter the file name again.";
        }
    }
    break;
}  // ADD THIS
	   case 5:///////////////////////5
{
    system("cls");
    drawBackground();
    setColor(11);
    setCursorPosition(35, 5);
    cout << "+------------------------------------------------+";
    setCursorPosition(35, 6);
    cout << "|";
    setCursorPosition(36, 6);
    int spaces = (48 - string("DISPLAY FILES").length()) / 2;
    for(int i = 0; i < spaces; i++)
    {
        cout << " ";
    }
    cout << "DISPLAY FILES";
    setCursorPosition(82, 6);
    cout << "|";
    setCursorPosition(35, 7);
    cout << "+------------------------------------------------+";
    setColor(15);
    setCursorPosition(35, 8);
    cout << "ACTIVE FILES";
    if(fileCount == 0)
    {
        setCursorPosition(35, 10);
        cout << "No active files.";
    }
    else
    {
        for(int j = 0; j < fileCount; j++)
        {
            if(j < 5)
            {
                setCursorPosition(35, 12 + j * 2);
            }
            else
            {
                setCursorPosition(60, 12 + (j - 5) * 2);
            }

            cout << f[j].file_name<< " (" << f[j].file_size << " blocks)";
        }
    }
    setCursorPosition(35, 22);
    cout << "Free Space: " << d.freespace << " blocks";
    setCursorPosition(35, 24);
    cout << "Press any key to return to Main Menu...";
    _getch();
    break;
}
case 6://///////////////////////////6
{
    system("cls");
    drawBackground();
    // FREE SPACE title
    setColor(11);
    setCursorPosition(35, 8);
    cout << "+------------------------------------------------+";
    setCursorPosition(35, 9);
    cout << "|";
    setCursorPosition(36, 9);
    int spaces = (48 - string("FREE SPACE").length()) / 2;
    for(int i = 0; i < spaces; i++)
    {
        cout << " ";
    }
    cout << "FREE SPACE";
    setCursorPosition(82, 9);
    cout << "|";
    setCursorPosition(35, 10);
    cout << "+------------------------------------------------+";
    setColor(15);
    setCursorPosition(35, 12);
    cout << "TOTAL DISK SPACE : 20 blocks";
    setCursorPosition(35, 14);
    cout << "USED SPACE       : "<< 20 - d.freespace << " blocks";
    setCursorPosition(35, 16);
    cout << "FREE SPACE       : "<< d.freespace << " blocks";
    setCursorPosition(35, 20);
    cout << "Press any key to return to Main Menu...";
    _getch();
    break;
}
case 7:
{
    saveData(f, fileCount);
    system("cls");
    drawBackground();
    setColor(11);
    setCursorPosition(35, 11);
    cout << "+------------------------------------------------+";
    setCursorPosition(35, 12);
    cout << "|                                                |";
    setCursorPosition(35, 13);
    cout << "|              EXITING SIMULATOR                 |";
    setCursorPosition(35, 14);
    cout << "|                                                |";
    setCursorPosition(35, 15);
    cout << "+------------------------------------------------+";
    setColor(15);
    setCursorPosition(35, 18);
    cout << "Thank you for using Virtual Data Recovery Simulator.";
    setCursorPosition(35, 20);
    cout << "Exiting program...";
    Sleep(1500);
    break;
}
default:
{
    cout << "Invalid choice!" << endl;
    cout << "\nPress any key to continue...";
    _getch();
    break;
}
} // switch
} while(menuChoice != 7);
   return 0;
}