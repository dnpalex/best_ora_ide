#include "ioadapter.h"

IOAdapter::IOAdapter(QObject *parent) : QObject(parent), LogableObject()
{

}

QStandardItemModel *IOAdapter::readFile(const QString &fileName, const IOAdapter::FileType &fileType)
{
    QStandardItemModel* model = Q_NULLPTR;
    QFile fl(fileName);
    if (!fl.open(QIODevice::ReadOnly))
    {
        emit LogError(fl.fileName().append(": ").append(fl.errorString()));
    }else{
        switch(fileType){
        case FileType::XML:{
            QDomDocument doc(fileName);
            QString errMsg; int errLine; int errCol;
            if(!doc.setContent(&fl,&errMsg,&errLine,&errCol)){
                emit LogError(errMsg.append(". line:").append(errLine).append(", column:").append(errCol));
            }else{
                model = new QStandardItemModel();
                recursiveRead(doc.documentElement(), *model->invisibleRootItem());
            }
            break;
        }
        case FileType::JSON:
            break;
        default:
            emit LogError(tr("Unsupported file type: "+fileType));
        }
    }
    fl.close();
    return model;
}

void IOAdapter::recursiveRead(const QDomElement &parElem, QStandardItem &parItem)
{
    QDomElement child = parElem.firstChildElement();
    QStandardItem* item = Q_NULLPTR;
    while(!child.isNull()){
        QDomNamedNodeMap attrList = child.attributes();
        QMap<QString,QVariant> userData;
        QDomAttr attr;
        for(int i = 0; i < attrList.count(); i++){
            attr = attrList.item(i).toAttr();
            userData.insert(attr.name(),createAttributeValue(attr.name(),attr.value()));
        }
        item = new QStandardItem(userData.value("ico").value<QIcon>(),userData.value("name").toString());
        item->setData(userData);
        parItem.appendRow(item);
        if(!child.firstChildElement().isNull()){
            recursiveRead(child,*item);
        }
        child = child.nextSiblingElement();
    }
}

QVariant IOAdapter::createAttributeValue(const QString &name, const QString &value)
{
    QVariant val;
    if(name=="ico"){
        val = QIcon(value);
    }else{
        val = value;
    }
    return val;
}


