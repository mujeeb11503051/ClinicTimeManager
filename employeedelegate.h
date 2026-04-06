#ifndef EMPLOYEEDELEGATE_H
#define EMPLOYEEDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class EmployeeDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit EmployeeDelegate(QObject *parent = nullptr);

    // Main rendering function
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

    // Defines the size of each "cell" in the grid
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;

private:
    // Constants for styling to keep code clean
    const int m_padding = 8;
    const int m_borderRadius = 10;

    const QColor m_borderColor = QColor(220, 220, 220); // Equivalent to #DCDCDC
    const QColor m_nameColor    = QColor(44, 62, 80);    // Equivalent to #2C3E50
    const QColor m_idColor      = QColor(127, 140, 141); // Equivalent to #7F8C8D
    const QColor m_highlight    = QColor(52, 152, 219);  // A nice blue for selection
};

#endif // EMPLOYEEDELEGATE_H
