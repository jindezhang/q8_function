#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QObject>
#include <vector>
#include <utility>
#include <string>
#include <QDebug>
#include <iostream>

using namespace std;

class analysis : public QObject
{
    Q_OBJECT
public:
    bool is_analysis(string expr);
    explicit analysis(QObject *parent = nullptr);
protected:
    void Next();
    void E();
    void E1();
    void T();
    void T1();
    void F();
    int word_analysis( vector<pair<string, int>>& word, const string expr );

private:
    vector<pair<string, int>> word;

    int idx ;
    int sym;
    int err ;
signals:
    void is_rigth(bool b);
public slots:
};

#endif // ANALYSIS_H
