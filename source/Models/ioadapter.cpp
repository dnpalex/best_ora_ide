#include "ioadapter.h"

IOAdapter::IOAdapter(QObject *parent) : QObject(parent), LogableObject()
{

}

QStandardItemModel *IOAdapter::readFile(const QString &fileName, const IOAdapter::FileType &fileType)
{
    QFile* fl = new QFile(fileName);
    if (!fl->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        emit LogError(fl->fileName().append(": ").append(fl->errorString()));
        //return false;
    }
    switch(fileType){
    case FileType::XML:{
        //QXmlStreamReader xml(fl);
        //parseXml(&xml,rootItem);
        break;
    }
    case FileType::JSON:
        break;
    default:
        emit LogError(tr("Unsupported file type: "+fileType));
        //return false;
    }
    //return true;
}

//if(!xml->atEnd() && !xml->hasError())
//{
//    QXmlStreamReader::TokenType token = xml->readNext();
//    if(xml->name()=="tree") parseXml(xml,parent);
//    switch(token){
//    case QXmlStreamReader::StartElement:{
//        QMap<QString,QString> data;
//        foreach (QXmlStreamAttribute attr, xml->attributes()) {
//            data[attr.name().toString()] = attr.value().toString();
//        }
//        TreeItem* ti = getTreeItem(parent, data);
//        parent->insertChildren(ti,parent->childCount());
//        parseXml(xml,ti);
//        break;
//    }
//    case QXmlStreamReader::EndElement:
//        parseXml(xml,parent->parent());
//        break;
//    case QXmlStreamReader::Invalid:
//        emit LogError(xml->errorString());
//        throw xml->error();
//        break;
//    case QXmlStreamReader::EndDocument:
//        return;
//    default:
//        parseXml(xml,parent);
//        break;
//    }
//}
