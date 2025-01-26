
#include "application.h"
#include "model/placesmodel.h"
#include "model/foldermodel.h"
#include "model/pathbarmodel.h"
#include "model/positioner.h"
#include "widgets/rubberband.h"
#include "widgets/itemviewadapter.h"
#include "desktop/desktop.h"
#include "desktop/desktopsettings.h"
#include "desktop/desktopview.h"
#include "helper/datehelper.h"
#include "helper/fm.h"
#include "helper/shortcut.h"

#include "draganddrop/declarativedragdropevent.h"
#include "draganddrop/declarativedroparea.h"
#include "draganddrop/declarativemimedata.h"

#include <QMimeData>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);

    // Register QML Type.
    const char *uri = "Cutefish.FileManager";
    const char *dragandrop_uri = "Cutefish.DragDrop";

    qmlRegisterType<PlacesModel>(uri, 1, 0, "PlacesModel");
    qmlRegisterType<FolderModel>(uri, 1, 0, "FolderModel");
    qmlRegisterType<PathBarModel>(uri, 1, 0, "PathBarModel");
    qmlRegisterType<Positioner>(uri, 1, 0, "Positioner");
    qmlRegisterType<RubberBand>(uri, 1, 0, "RubberBand");
    qmlRegisterType<ItemViewAdapter>(uri, 1, 0, "ItemViewAdapter");
    qmlRegisterType<DesktopSettings>(uri, 1, 0, "DesktopSettings");
    qmlRegisterType<Fm>(uri, 1, 0, "Fm");
    qmlRegisterType<ShortCut>(uri, 1, 0, "ShortCut");

#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0)
    qmlRegisterType<QAction>();
    qmlRegisterType<QMimeData>();
#else
    qmlRegisterAnonymousType<QAction>(uri, 1);
    qmlRegisterAnonymousType<QMimeData>(dragandrop_uri, 1);
#endif

    qmlRegisterType<DeclarativeDropArea>(dragandrop_uri, 1, 0, "DropArea");
    qmlRegisterUncreatableType<DeclarativeMimeData>(dragandrop_uri, 1, 0, "MimeData", QStringLiteral("MimeData cannot be created from QML."));
    qmlRegisterUncreatableType<DeclarativeDragDropEvent>(dragandrop_uri, 2, 0, "DragDropEvent", QStringLiteral("DragDropEvent cannot be created from QML."));

    Application app(argc, argv);
    return app.run();
}
