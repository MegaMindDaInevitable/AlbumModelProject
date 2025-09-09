
#include "albummodel.h"
#include <QString>

AlbumModel::AlbumModel(QObject *parent): QAbstractTableModel(parent)
{

}

int AlbumModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return m_albums.size();
}
