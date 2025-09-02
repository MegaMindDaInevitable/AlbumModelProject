
#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractTableModel>
#include <QList>


class AlbumModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    explicit AlbumModel(QObject *parent = nullptr);

    //requred overrrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
};

#endif // ALBUMMODEL_H
