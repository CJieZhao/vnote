#ifndef VOUTLINE_H
#define VOUTLINE_H

#include <QTreeWidget>
#include "vtoc.h"

class VOutline : public QTreeWidget
{
    Q_OBJECT
public:
    VOutline(QWidget *parent = 0);

signals:
    void outlineItemActivated(const VAnchor &anchor);

public slots:
    void updateOutline(const VToc &toc);

private slots:
    void handleItemClicked(QTreeWidgetItem *item, int column);

private:
    void updateTreeFromOutline(const VToc &toc);
    void updateTreeByLevel(const QVector<VHeader> &headers, int &index, QTreeWidgetItem *parent,
                           QTreeWidgetItem *last, int level);
    void expandTree();

    VToc outline;
};

#endif // VOUTLINE_H