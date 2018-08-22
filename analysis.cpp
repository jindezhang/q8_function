#include "analysis.h"

bool analysis::is_analysis(string expr)
{
    word.clear();
    idx = 0;
    err = 0;

    int err_num = word_analysis( word, expr );
    cout << expr << endl << "***Word Analysis:" << endl;
    if ( -1 == err_num )
    {
        cout << "Word Error!" << endl;
        emit is_rigth(false);
        return false;
    }
    else
    {
        // 测试输出
        vector<pair<string, int>>::iterator beg = word.begin();
        for ( ; beg != word.end(); ++beg )
            cout << "   (" << beg->first << ", " << beg->second << ")" << endl;

        // 词法正确，进行语法分析
        Next();
        E();
        if ( sym == 0 && err == 0 )  // 注意要判断两个条件
        {
            cout << "Right Expression." << endl;
            emit is_rigth(true);
            return true;
        }

        else
        {
            cout << "Wrong Expression." << endl;
            emit is_rigth(false);
            return false;
        }


    }

}

analysis::analysis(QObject *parent) : QObject(parent)
{
     idx = 0;
     err = 0; // 错误
}

void analysis::Next()
{
    if ( idx < word.size() )
        sym = word[ idx++ ].second;
    else
        sym = 0;
}

void analysis::E()
{
    T();
    E1();

}

void analysis::E1()
{
    if ( sym == 1 )
    {
        Next();
        T();
        E1();
    }
    else if ( sym == 2 )
    {
        Next();
        T();
        E1();
    }
    else if ( sym != 7 && sym != 0 )
    {
        err = -1;
    }

}

void analysis::T()
{
    F();
    T1();
}

void analysis::T1()
{
    if ( sym == 3 )
    {
        Next();
        F();
        T1();
    }
    else if ( sym == 4 )
    {
        Next();
        F();
        T1();
    }
    else if ( sym != 1 && sym != 2 && sym != 7 && sym != 0 )
    {
        err = -1;
    }
}

void analysis::F()
{
    if ( sym == 5 )
    {
        Next();
    }
    else if ( sym == 6 )
    {
        Next();
        E();
        if ( sym == 7 )
        {
            Next();
        }
        else
        {
            err = -1;
        }
    }
    else
    {
        err = -1;
    }
}

int analysis::word_analysis(vector<pair<string, int> > &word, const string expr)
{
    for ( int i = 0; i < expr.length(); ++i )
        {
            // 如果是 + - * / ( )
            if ( expr[ i ] == '(' || expr[ i ] == ')' || expr[ i ] == '+'
                || expr[ i ] == '-' || expr[ i ] == '*' || expr[ i ] == '/' )
            {
                string tmp;
                tmp.push_back( expr[ i ] );
                switch ( expr[ i ] )
                {
                    case '+':
                        word.push_back( make_pair( tmp, 1 ) );
                        break;
                    case '-':
                        word.push_back( make_pair( tmp, 2 ) );
                        break;
                    case '*':
                        word.push_back( make_pair( tmp, 3 ) );
                        break;
                    case '/':
                        word.push_back( make_pair( tmp, 4 ) );
                        break;
                    case '(':
                        word.push_back( make_pair( tmp, 6 ) );
                        break;
                    case ')':
                        word.push_back( make_pair( tmp, 7 ) );
                        break;
                }
            }
            // 如果是数字开头
            else if ( expr[ i ] >= '0' && expr[ i ] <= '9' )
            {
                string tmp;
                while ( expr[ i ] >= '0' && expr[ i ] <= '9' )
                {
                    tmp.push_back( expr[ i ] );
                    ++i;
                }
                if ( expr[ i ] == '.' )
                {
                    ++i;
                    if ( expr[ i ] >= '0' && expr[ i ] <= '9' )
                    {
                        tmp.push_back( '.' );
                        while ( expr[ i ] >= '0' && expr[ i ] <= '9' )
                        {
                            tmp.push_back( expr[ i ] );
                            ++i;
                        }
                    }
                    else
                    {
                        return -1;  // .后面不是数字，词法错误
                    }
                }
                word.push_back( make_pair( tmp, 5 ) );
                --i;
            }
            // 如果以.开头
            else
            {
                return -1;  // 以.开头，词法错误
            }
        }
        return 0;
}
