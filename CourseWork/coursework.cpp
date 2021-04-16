
#include <iostream>
#include "Video.h"
#include "Movie.h"
#include "Series.h"
#include "Cartoon.h"
#include "Collection.h"

int main()
{
    Movie* m = new Movie;
    Series* s = new Series;
    Cartoon* c = new Cartoon;
    
    m->printParams();
    s->printParams();
    c->printParams();

    Collection col;
    //col.addVideo(m);
    //col.addVideo(s);
    //col.addVideo(c);
    col.fGetData("input.txt");
    std::cout << "\n" << col.getCount() << "\n";
    col.fPrintData("output.txt");
}
