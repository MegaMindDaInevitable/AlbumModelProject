
#include "albummodel.h"
#include <QString>

AlbumModel::AlbumModel(QObject *parent): QAbstractTableModel(parent)
{

}

int AlbumModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return m_albums.size();
}

int AlbumModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);

    return 4;
}


QVariant AlbumModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    const Album &album = m_albums[index.row()];

    switch (index.column())
    {
    case 0: return album.composer;
    case 1: return album.albumName;
    case 2: return QString::number(album.cost, 'f', 2);
    case 3: return album.rating;
    default : return QVariant();


    }
}

QVariant AlbumModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();
}
