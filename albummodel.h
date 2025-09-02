
#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H


#include <QObject>
#include <QWidget>
#include <QAbstractTableModel>
#include <QList>


class AlbumModel
{
public:
    explicit AlbumModel(QObject *parent = nullptr);
    //requred overrrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVarient data(const QModelIndex &index, int role = Qt::DisplayRole) const overrride;
};

#endif // ALBUMMODEL_H
