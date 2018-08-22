#ifndef ANALYSIS_2_H
#define ANALYSIS_2_H

#include <QObject>


/*
 * AST 是项目名。[AST1]
 *  负数检测。pow是平方。ABS是绝对值。逗号只用于log值。
 */
class analysis_2 : public QObject
{
    Q_OBJECT
public:
    explicit analysis_2(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ANALYSIS_2_H
