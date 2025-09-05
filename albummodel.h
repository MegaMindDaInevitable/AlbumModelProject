
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

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    //custom methods

    void addAlbum(const QStrng &composer, const QString &albumName, double cost, int rating);

    void removeAlbum(int row);

private:
    struct AlbumModel
    {
        QString composer;
        QString albumName;
        double cost;

    }
};

#endif // ALBUMMODEL_H
