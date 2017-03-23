#include "ioadapter.h"

IOAdapter::IOAdapter(QObject *parent) : QThread(parent), LogableObject(), AdapterAbstract(), SettingsUser()
{
}

void IOAdapter::RequestModel(const ViewAbstract::ViewType &viewType)
{
    switch (viewType) {
    case ViewAbstract::ConnectionList:{
        emit ModelFinished(ReadFile(configValue(tr("Connections"),tr("fileName")).toString(),
                                    InterpretFileType(configValue(tr("Connections"),tr("fileType")).toString())),
                           viewType);
        break;
    }
    case ViewAbstract::QueryEditor:
        break;
    case ViewAbstract::OutPut:
        break;
    case ViewAbstract::Default:
        break;
    }
}

QStandardItemModel *IOAdapter::ReadFile(const QString &fileName, const IOAdapter::FileType &fileType)
{
    QStandardItemModel* model = Q_NULLPTR;
    switch(fileType){
    case FileType::XML:{
        QDomDocument* doc = Q_NULLPTR;
        doc = ReadXmlFile(AcquireDir(tr("Config")).dirName().append(QDir::separator()).append(fileName));
        if(doc!=Q_NULLPTR){
            model = new QStandardItemModel(this);
            RecursiveRead(doc->documentElement(), *model->invisibleRootItem());
        }
        break;
    }
    case FileType::JSON:
        break;
    case FileType::UNKNOWN:
        emit LogError(tr("Unsupported file type: ").append(fileType));
        break;
    }
    return model;
}

QDomDocument *IOAdapter::ReadGlobSettings(bool refresh)
{
    if(refresh){
        ReadXmlFile(configValue(tr("Config"),tr("globFileName")).toString(),//AcquireDir(tr("Config")).dirName().append(QDir::separator()).append(),
                    &globalSettings);
    }
    return &globalSettings;
}

void IOAdapter::run()
{
    exec();
}

void IOAdapter::RecursiveRead(const QDomElement &parElem, QStandardItem& parItem)
{
    QDomElement child = parElem.firstChildElement();
    QStandardItem* item = Q_NULLPTR;
    while(!child.isNull()){
        QDomNamedNodeMap attrList = child.attributes();
        QMap<QString,QVariant> userData;
        QDomAttr attr;
        for(int i = 0; i < attrList.count(); i++){
            attr = attrList.item(i).toAttr();
            userData.insert(attr.name(),QtXML::CreateAttributeValue(attr));
        }
        item = new QStandardItem(userData.value(tr("icon")).value<QIcon>(),userData.value("name").toString());
        item->setData(userData);
        parItem.appendRow(item);
        if(!child.firstChildElement().isNull()){
            RecursiveRead(child,*item);
        }
        child = child.nextSiblingElement();
    }
}

IOAdapter::FileType IOAdapter::InterpretFileType(const QString &ftName)
{
    if(ftName == "XML") return IOAdapter::XML;
    else if (ftName == "JSON") return IOAdapter::JSON;
    return IOAdapter::UNKNOWN;
}

QDomDocument* IOAdapter::ReadXmlFile(const QString &fileName, QDomDocument *doc)
{
    QFile fl(fileName);
    QDomDocument* d = Q_NULLPTR;
    if (!fl.open(QIODevice::ReadOnly))
    {
        emit LogError(fl.fileName().append(": ").append(fl.errorString()));
    }else{
        QString errMsg; int errLine; int errCol;
        d = doc==Q_NULLPTR ? new QDomDocument() : doc;
        if(!d->setContent(&fl,&errMsg,&errLine,&errCol)){
            if(doc==Q_NULLPTR) delete d;
            d = Q_NULLPTR;
            emit LogError(errMsg.append(". line:").append(errLine).append(", column:").append(errCol));
        }
    }
    fl.close();
    return d;
}

QDir IOAdapter::AcquireDir(const QString &configGroup)
{
    QDir dir(configValue(configGroup,tr("folder")).toString());
    if(!dir.exists())
        dir.mkpath(dir.absolutePath());
    return dir;
}


