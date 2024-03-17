#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "sortingalgorithms.h"
#include "otherfunctionss.h"


sf::RenderWindow SORTWINDOW(sf::VideoMode(600,600),"SORTING ALGORITHMS" ,sf::Style::Close | sf::Style::Titlebar);
void Drawrectangle(int array[],int size)
{
    int width = 600/size;
    int margin = (600 - (width*size))/2;
    for (int i = 0 ; i < size ;i ++)
    {
        int height = array[i] * 6;
        sf::RectangleShape rectangle; 
        rectangle.setSize(sf::Vector2f(width,height)); // Set size
        rectangle.setPosition(margin + width*i,600 - height); // Set position
        double x = getwavelenght(array[i]);
        std::vector<int> rgb = wavelength_to_rgb(x);
        int red = rgb[0];
        int green = rgb[1];
        int blue = rgb[2];
        rectangle.setFillColor(sf::Color(red,green,blue)); // Set color
        SORTWINDOW.draw(rectangle); // Draw rectangle  
    }
}
void printchange(int array[], int size)
{
    for (int i = 0 ; i < size ;i ++)
    {
        std::cout << array[i] <<' ';
    }
    std::cout << std::endl;
    SORTWINDOW.clear();
    Drawrectangle(array,size);
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    SORTWINDOW.display();
}

int main() 
{
    using namespace std;
    char c;
    cout << "Custom 'c' Random 'r'" <<endl;
    cout << "Number of elements between 0 to 100" <<endl;
    cout << "each element form 0 to 100"<<endl;
    cin >> c;
    int n;
    cin >> n;
    int array1[n];
    int source1[n];
    if (c == 'c')
    {
        for (int i = 0 ; i < n ; i ++)
        {
            int a;
            cin >> a;
            array1[i] = a;
            source1[i] = a;
        }
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            int a = randomnumbetween(1,100);
            array1[i] = a;
            source1[i] = a;
        }
        
    }
    cout << "Enter Sorting Algorithm \n Bubble Sort(B) \n Selection Sort(S) \n Insertion Sort(I) \n Merge Sort(M) \n Quick Sort(Q) \n QUIT for exiting the program. \n (CA) to change or redifine the array \n help (HELP) \n";
    SORTWINDOW.clear();
    Drawrectangle(array1,n);
    SORTWINDOW.display();
    while(SORTWINDOW.isOpen())
    {
        sf::Event wevent;
        while(SORTWINDOW.pollEvent(wevent))
        {
            if(wevent.type == sf::Event::Closed)
            {
                SORTWINDOW.close();
            }
            else
            {
                continue;
            }
        }
        string salgo;
        cin >> salgo;
        if(salgo == "B")
        {
            SORTWINDOW.clear();
            Drawrectangle(array1,n);
            SORTWINDOW.display();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "BUBBLESORT" <<endl;
            bubblesort(array1,n);
            CopyArray(source1,array1,n);
        }
        else if(salgo == "S")
        {
            SORTWINDOW.clear();
            Drawrectangle(array1,n);
            SORTWINDOW.display();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "SELECTIONSORT" <<endl;
            selectionsort(array1,n);
            CopyArray(source1,array1,n);   
        }
        else if(salgo == "I")
        {
            SORTWINDOW.clear();
            Drawrectangle(array1,n);
            SORTWINDOW.display();    
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "INSERTIONSORT" <<endl;
            insertionsort(array1,n);
            CopyArray(source1,array1,n);
        }
        else if(salgo == "Q")
        {
            SORTWINDOW.clear();
            Drawrectangle(array1,n);
            SORTWINDOW.display();    
            std::this_thread::sleep_for(std::chrono::seconds(1));         
            cout << "QUICKSORT" <<endl;
            quicksort(array1,0,n-1,n);
            CopyArray(source1,array1,n);
        }
        else if(salgo == "M")
        {
            SORTWINDOW.clear();
            Drawrectangle(array1,n);
            SORTWINDOW.display();             
            std::this_thread::sleep_for(std::chrono::seconds(1)); 
            cout << "MERGESORT" <<endl;
            mergesort(array1,0,n-1,n);
            CopyArray(source1,array1,n);            
        }
        else if(salgo == "QUIT")
        {            
            SORTWINDOW.close();
            break;
        }
        else if(salgo == "CA")
        {
            cout << "Custom 'c' Random 'r'" <<endl;
            cout << "Number of elements between 0 to 100" <<endl;
            cout << "each element form 0 to 100"<<endl;
            cin >> c;
            cin >> n;
            if (c == 'c')
            {
                for (int i = 0 ; i < n ; i ++)
                {
                    int a;
                    cin >> a;
                    array1[i] = a;
                    source1[i] = a;
                }
            }
            else
            {
                for (size_t i = 0; i < n; i++)
                {
                    int a = randomnumbetween(1,100);
                    array1[i] = a;
                    source1[i] = a;
                }
                
            }
            SORTWINDOW.clear();
            Drawrectangle(array1,n);
            SORTWINDOW.display();
        }
        else if(salgo == "HELP")
        {
            cout << "Enter Sorting Algorithm \n Bubble Sort(B) \n Selection Sort(S) \n Insertion Sort(I) \n Merge Sort(M) \n Quick Sort(Q) \n QUIT for exiting the program. \n (CA) to change or redifine the array \n help (HELP) \n";            
        }
        else
        {
            cout << "INVALID INPUT" <<endl;
        }
    }
    return 0;
}