//hangman.cpp -- some string methods
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using std::string;
const int NUM  =26;
const string wordlist[NUM] = {"apiary", "beetle", "cereal", "danger", "ensign",
"florid", "garage", "health", "insult", "jackal", "keeper", "loaner", "manage",
"nonce", "onset", "valid", "plaid", "quilt", "remote", "stolid", "train", "useful",
"whence", "xenon", "yearn", "zippy"
};

int main ()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    std::srand(std::time(0));   //用1970.1.1至今的秒数(time)，初始化随机数种子
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);  //变小写
    while(play == 'y')
    {
        string target = wordlist[std::rand() % NUM];    //0-25随机数
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout <<  "Guess my secret word.It has " << length
            << " letters, and you guess\n"
            << "one letter at a time .You get " << guesses
            << " wrong guesses.\n";
            cout << "Your word:" << attempt << endl;
            while (guesses > 0 && attempt != target)
            {
                char letter;
                cout << "Guess a letter: ";
                cin >> letter;
                if(badchars.find(letter) != string::npos
                   || attempt.find(letter) != string::npos)   //string::npos是个特殊值，说明查找没有匹配
                {
                    cout << "You already guessed that,Try again.\n";
                    continue;
                }
                int loc = target.find(letter);
                if (loc == string::npos)          //猜的字母不对
                {
                    cout << "Oh,bad guess!\n";
                    --guesses;
                    badchars += letter; //add to string
                }
                else
                {
                    cout << "Good guess!\n";
                    attempt[loc] = letter;
                    //check if letter appear again
                    loc = target.find(letter, loc+1);
                    while (loc != string::npos)
                    {
                        attempt[loc] = letter;
                        loc = target.find(letter, loc + 1);
                    }
                }
                cout << "Your word:" << attempt << endl;
                if (attempt != target)
                {
                    if(badchars.length() > 0)
                        cout << "Bad choices: " << badchars <<endl;
                    cout << guesses << " bad guesses left\n";
                }
            }
            if (guesses > 0)
                cout << "That's right!\n";
            else
                cout << "Sorry , the word is " << target << ".\n";

            cout << "Will you play another?<y/n> ";
            cin >> play;
            play = tolower(play);
    }
    cout << "Bye.\n";

    return 0;
}
