#include "employeedelegate.h"


EmployeeDelegate::EmployeeDelegate(QObject *parent)
{

}

void EmployeeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->setRenderHint(QPainter::Antialiasing);

    // 1. Setup the card rectangle
    QRect rect = option.rect.adjusted(m_padding, m_padding, -m_padding, -m_padding);

    // 2. Draw Background
    if (option.state & QStyle::State_Selected) {
        painter->setBrush(m_highlight.lighter(180)); // Light blue highlight
        painter->setPen(QPen(m_highlight, 2));       // Thicker blue border
    } else {
        painter->setBrush(Qt::white);
        painter->setPen(QPen(m_borderColor, 1));
    }
    painter->drawRoundedRect(rect, m_borderRadius, m_borderRadius);

    // 3. Get Data (Check your DB column indexes!)
    // Assuming: Col 1 = Name, Col 4 = Personal Number
    QString name = index.model()->data(index.model()->index(index.row(), 1)).toString();
    QString id   = index.model()->data(index.model()->index(index.row(), 3)).toString();

    // 4. Draw Name (Bold, Center-Top)
    painter->setPen(m_nameColor);
    QFont nameFont = painter->font();
    nameFont.setBold(true);
    nameFont.setPointSize(10);
    painter->setFont(nameFont);

    // Draw name in the top half of the card
    QRect nameRect = rect.adjusted(5, 15, -5, -rect.height()/2);
    painter->drawText(nameRect, Qt::AlignCenter | Qt::ElideRight, name);

    // 5. Draw ID (Smaller, Center-Bottom)
    painter->setPen(m_idColor);
    QFont idFont = painter->font();
    idFont.setBold(false);
    idFont.setPointSize(8);
    painter->setFont(idFont);

    // Draw ID in the bottom half
    QRect idRect = rect.adjusted(5, rect.height()/2, -5, -10);
    painter->drawText(idRect, Qt::AlignCenter, "ID: " + id);
}

QSize EmployeeDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(200, 100); // The size of one "cell" in your grid
}
