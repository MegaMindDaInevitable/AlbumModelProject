
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
    switch(section)
    {
    case 0: return "Composer";
    case 1: return "Album Name";
    case 2: return "Cost";
    case 3: return QVariant();
    }

}


bool AlbumModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role != Qt::EditRole || !index.isValid())
        return false;

    Album &album = m_albums[index.isValid()];
    switch (index.column())
    {
    case 0: album.composer = value.toString(); break;
    case 1: album.albumName = value.toString(); break;
    case 2: album.cost = value.toInt(); break;
    case 3: album.rating = value.toInt(); break;
    default: return false;
    }

    emit dataChanged(index, index);
    return true;
}
Qt::ItemFlags AlbumModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
