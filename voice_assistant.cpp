#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctime> // must include this header file to use time function
#include <fstream> //to read files

using namespace std;

// function to wish user according to time
void wishme(){
    // current date  and time based on your system timezone
    time_t now = time(0);
    tm *time = localtime(&now);

    if (time-> tm_hour < 12){
        cout<< "Good Morning "<<endl;
        string phrase = "Good Morning ";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    }

    else if (time-> tm_hour >= 12 && time->tm_hour <= 16){
        cout<< "Good Afternoon "<<endl;
        string phrase = "Good Afternoon ";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    }
    
    else if (time-> tm_hour > 16 && time->tm_hour < 24){
        cout<< "Good Evening "<<endl;
        string phrase = "Good Evening ";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    }
}

void datetime(){
    time_t now = time(0);
    char *dt = ctime(&now);
    cout<<"The date and time is "<<endl
        << dt <<endl;
}

int main()
{
    system("cls");

    cout<<"\t\t\t<=============================================      W E L C O M E      ==========================================>"<<endl;
    cout<<"\t\t\t<============================================= I'M A VIRTUAL ASSISTANT ==========================================>"<<endl;
    cout<<"\t\t\t<=============================================     MY NAME IS ASH      ==========================================>"<<endl;
    cout<<"\t\t\t<=============================================   I'M HERE TO HELP YOU  ==========================================>"<<endl<<endl;

    char password[20]; //to take password
    char ch[100]; // to take command from the user
    char name[100];

    do
    {
        cout<<"======================="<<endl;
        cout<<"| ENTER YOUR PASSWORD |"<<endl;
        cout<<"======================="<<endl<<endl;
        string phrase = "enter your password";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

        gets(password);

        cout<<"======================="<<endl;
        cout<<"| ENTER YOUR NAME     |"<<endl;
        cout<<"======================="<<endl<<endl;
        phrase = "enter your name";
        command = "espeak \"" + phrase + "\"";
        charCommand = command.c_str();
        system(charCommand);

        gets(name);

        STARTUPINFO startInfo = {0};
        PROCESS_INFORMATION processInfo = {0};

        if(strcmp(password, "inertia")==0){
            cout<<"\n<==================================================================================================>\n\n";
            wishme();
            do{
                cout<<"\n<==================================================================================================>\n\n";
                cout<<endl<<"How can i help you "<<name<<"...."<<endl<<endl;

                string phrase1 = "How can i help you ";
                string phrase = phrase1 + name;
                string command = "espeak  \"" + phrase + "\""; //espeak  -v +f3 \ for female voice
                const char *charCommand = command.c_str();
                system(charCommand);

                cout<<"Your query ===> ";
                gets(ch);
                cout<<endl;
                cout<<"Here is the result for your query ===> ";

                if(strcmp(ch, "hi") == 0 || strcmp(ch, "hey") == 0 || strcmp(ch, "hello") == 0 ){
                    cout<<"Hello "<<name<<"....."<<endl;
                    string phrase1 = "Hello ";
                    string phrase = phrase1 + name;
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                }
                else if(strcmp(ch, "play a song") == 0)
                {
                    cout<<"playing a song "<<endl;
                    string phrase = "playing a song on youtube ";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    system("start https://www.youtube.com/watch?v=tqBTGJ3FXRE");
                }
                else if(strcmp(ch, "bye") == 0 || strcmp(ch, "stop") == 0 || strcmp(ch, "exit") == 0 ){
                    cout<<"Good Bye "<<name<<" , have a nice day !!!!"<<endl;
                    string phrase1 = "Good Bye";
                    string phrase2 = "have a nice day";
                    string phrase = phrase1 + name + phrase2;
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    exit(0);
                }
                
                else if(strcmp(ch, "who are you") == 0 || strcmp(ch, "tell me about yourself") == 0 || strcmp(ch, "about") == 0 ){
                    cout<<"I'm a virtual assistant !!!"<<endl;
                    string phrase = "I am a virtual assistant Ash";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                }

                else if(strcmp(ch, "how are you") == 0 || strcmp(ch, "whatsup") == 0 || strcmp(ch, "how is your day") == 0 ){
                    cout<<"I'm good "<<name <<" , tell me how can i help you.."<<endl;
                    string phrase1 = "I'm good ";
                    string phrase2 = ", tell me how can i help you";
                    phrase = phrase1 +name +phrase2;
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                }

                else if(strcmp(ch, "time") == 0 || strcmp(ch, "date") == 0){
                    // make function to show date and time
                    datetime();
                }

                else if(strcmp(ch, "open notepad") == 0){
                   cout<<"openining notepad....."<<endl;
                   string phrase = "opening notepad";
                   string command = "espeak \"" + phrase + "\"";
                   const char *charCommand = command.c_str();
                   system(charCommand);
                   CreateProcess(TEXT("C:\\Windows\\notepad.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
                }

                else if(strcmp(ch, "read me something") == 0){
                   cout<<"openining notepad....."<<endl;
                   string phrase = "okay i'll read to you about c++";
                   string command = "espeak \"" + phrase + "\"";
                   const char *charCommand = command.c_str();
                   system(charCommand);
                   system("start C:\\Users\\Tharika\\Desktop\\about.txt");
                   ifstream in_file;
                   string line;
                   in_file.open("C:\\Users\\Tharika\\Desktop\\about.txt");
                   if(!in_file)
                   {
                        cerr<<"problem opening file"<<endl;
                        break;
                   }
                   if(in_file)
                   {
                        cout<<"opened file successfully"<<endl;
                        while(getline(in_file, line))
                        {
                            
                            //in_file >> line;
                            cout<<line<<endl;
                            phrase = line;
                            string command = "espeak \"" + phrase + "\"";
                            const char *charCommand = command.c_str();
                            system(charCommand);
                        }
                   }
                    in_file.close();
                }

                else if(strcmp(ch, "open google") == 0){
                    cout<<"opening google....."<<endl;
                    string phrase = "opening google";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    system("start https://www.google.com");
                }

                else if(strcmp(ch, "open youtube") == 0){
                    cout<<"opening YouTube....."<<endl;
                    string phrase = "opening youtube";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    system("start https://www.youtube.com");
                }

                else if(strcmp(ch, "open instagram") == 0){
                    cout<<"openining instagram....."<<endl;
                    string phrase = "opening instagram";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                    system("start https://www.instagram.com");
                }

                else{
                    cout<<"Sorry could not understand your query please ty again !!!"<<endl;
                    string phrase = "Sorry could not understand your query please ty again";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                }


            }while(1);
        }
        else
                {
                    system("cls");

                    cout<<"\t\t\t<=============================================     W E L C O M E       ==========================================>"<<endl;
                    cout<<"\t\t\t<============================================= I'M A VIRTUAL ASSISTANT ==========================================>"<<endl;
                    cout<<"\t\t\t<=============================================     MY NAME IS ASH      ==========================================>"<<endl;
                    cout<<"\t\t\t<=============================================   I'M HERE TO HELP YOU  ==========================================>"<<endl<<endl;

                    cout << "======================" << endl;
                    cout << "X Incorrect Password X" << endl;
                    cout << "======================" << endl
                         << endl;
                    string phrase = "Incorrect Password, Please enter correct password";
                    string command = "espeak \"" + phrase + "\"";
                    const char *charCommand = command.c_str();
                    system(charCommand);
                }
    } while (1);
    

    return 0;
}
