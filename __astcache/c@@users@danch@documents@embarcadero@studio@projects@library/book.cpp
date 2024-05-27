#include <iostream>
#include <ctime>
using namespace std;


#include "Book.h"



wstring PrintGenre( Genre genre )
{
    switch(genre)
    {
        case Genre::Drama : return L"пьеса";
        case Genre::Novel : return L"роман";
        case Genre::Poem : return L"поэма";
        case Genre::Tale : return L"повесть";
        default: return L"Неизвестно";
    }
}

wstring PrintDiscipline( Discipline discipline)
{
    switch(discipline)
    {
        case Discipline::Economics : return L"Экономика";
        case Discipline::Philosophy : return L"Философия";
        case Discipline::Physics : return L"Физика";
        case Discipline::Programming : return L"Программирование";
        default: return L"Неизвестно";
    }
}

wstring PrintTheme( Theme theme)
{
    switch(theme)
    {
        case Theme::Auto : return L"Автомобили";
        case Theme::Sport : return L"Спорт";
        case Theme::Science : return L"Наука";
        default: return L"Неизвестно";
    }
}

Book::Book()
{
    publicationYear = (rand() % 20) + 1980;
    condition = rand() % 100;
    numberOfPage = (rand() % 150) + 150;
}


BookContainer1::BookContainer1(int maxQuantity)
{
    Bookcase = new PtrBook[maxQuantity];

    for(int i = 0; i<maxQuantity ; i++)
    {
        Bookcase[i] = NULL;
    }

    MaxQuantity = maxQuantity;
    BookQuantity = 0;
}

BookContainer1::~BookContainer1()
{
    for(int i=0; i< MaxQuantity; i++)
    {
        if(Bookcase[i] != NULL)
        {
            delete Bookcase[i];
            Bookcase[i] = NULL;
        }
    }

    delete[] Bookcase;
}

void BookContainer1::AddBook(PtrBook book)
{
    if(BookQuantity != MaxQuantity)
    {
        Bookcase[BookQuantity++] = book;
    }
    else
    {
        wcout<< L"Контейнер полон!!!" << endl;
    }
}

BookContainer2::~BookContainer2()
{
    for(int i=0; i< Bookcase.size(); i++)
    {
        if(Bookcase[i] != NULL)
        {
            delete Bookcase[i];
            Bookcase[i] = NULL;
        }
    }
}

Book* Book::createBook(BookType type)
{
    switch(type)
    {
        case BookType::Fiction: return new Fiction;
        case BookType::Journal: return new Journal;
        case BookType::Textbook: return new Textbook;
        default: return nullptr;
    }
}

BookType RandomBookType()
{
    return BookType(rand()%3);
}

BookContainer3::BookContainer3()
{
    int  openResult = sqlite3_open("Library.db", &Database);

    if(openResult != SQLITE_OK)//если не смогли открыть базу данных
    {
        wcout << L"Ошибка открытия базы данных!" << endl;
    }

    id = 1;
}

BookContainer3::~BookContainer3()
{
    string request = "DELETE FROM books";

    char *errmsg;

    int execResult = sqlite3_exec(Database, request.c_str(), NULL, 0, &errmsg);

    if(execResult != SQLITE_OK)
    {
        wcout << L"Ошибка выполнения запроса!" << endl;
        cout << errmsg << endl;
    }

    int close_result = sqlite3_close(Database);

    if(close_result == SQLITE_OK)
    {
        wcout << L"Файл(База данных) закрылся" << endl;
    }

}

void BookContainer3::AddBook(PtrBook book)
{
    int year = book->GetYear();
    int condition = book->GetCondition();
    int pages = book->GetNumberOfPage();
    int specific;
    int type = (int)book->GetType();
    switch(type)
    {
        case 0:
            specific = (int)(((Fiction *)book)->GetGenre());
            break;
        case 1:
            specific = (int)(((Textbook *)book)->GetDisc());
            break;
        case 2:
            specific = (int)(((Journal *)book)->GetTheme());
            break;
    }

    string request = "INSERT INTO books (Id, Year, Pages, Condition, Specific, Type) VALUES (" + to_string(id) + ", "
                                                                                               + to_string(year) + ", "
                                                                                               + to_string(pages) + ", "
                                                                                               + to_string(condition) + ", "
                                                                                               + to_string(specific) + ", "
                                                                                               + to_string(type) + ")";
    id++;

    cout << request << endl;

    char *errmsg;

    int execResult = sqlite3_exec(Database, request.c_str(), NULL, 0, &errmsg);

    if(execResult != SQLITE_OK)
    {
        wcout << L"Ошибка выполнения запроса!" << endl;
        cout << errmsg << endl;
    }

}

int BookContainer3::GetQuantity() const
{
    string request = "SELECT count(*) FROM books";

    sqlite3_stmt *pStatement;

    int execResult2 = sqlite3_prepare_v2(Database,
                                         request.c_str(),
                                         -1, //здесь можно написать длину второго параметра
                                         &pStatement, NULL);

    if(execResult2 != SQLITE_OK)
    {
        wcout << "Ошибка подготовки запроса!" << endl;
        const char *errmsg2 = sqlite3_errmsg(Database);
        cout << errmsg2 << endl;
    }
    //выполнение запроса
    int execResult3 = sqlite3_step(pStatement);
    int n;
    if(execResult3 == SQLITE_ROW)
    {
        n = sqlite3_column_int(pStatement, 0 /* номер столбца*/);
    }

    sqlite3_finalize(pStatement); //очистка памяти
    return n;
}

PtrBook BookContainer3::GetByIndex(int i) const
{
    string request = "SELECT * FROM books WHERE Id=" + to_string(i);

    sqlite3_stmt *pStatement;

    int execResult2 = sqlite3_prepare_v2(Database,
                                         request.c_str(),
                                         -1, //здесь можно написать длину второго параметра
                                         &pStatement, NULL);

    if(execResult2 != SQLITE_OK)
    {
        wcout << "Ошибка подготовки запроса!" << endl;
        const char *errmsg2 = sqlite3_errmsg(Database);
        cout << errmsg2 << endl;
    }
    //выполнение запроса
    int execResult3 = sqlite3_step(pStatement);

    int year;
    int pages;
    int cond;
    int spec;
    int type;

    if(execResult3 == SQLITE_ROW)
    {
        year = sqlite3_column_int(pStatement, 1);
        pages = sqlite3_column_int(pStatement, 2);
        cond = sqlite3_column_int(pStatement, 3);
        spec = sqlite3_column_int(pStatement, 4);
        type = sqlite3_column_int(pStatement, 5);
    }

    switch((BookType)type)
    {
        case BookType::Fiction: sqlite3_finalize(pStatement); return new Fiction(year, pages, cond, spec);
        case BookType::Journal: sqlite3_finalize(pStatement); return new Journal(year, pages, cond, spec);
        case BookType::Textbook: sqlite3_finalize(pStatement); return new Textbook(year, pages, cond, spec);
        default: sqlite3_finalize(pStatement); return nullptr;
    }
}


