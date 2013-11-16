#pragma once

#include <QApplication>

#include "ExportDefines.h"

namespace mtq {

    struct ApplicationDetail;

    class MTQ_EXPORT Application : public QApplication
    {
        Q_OBJECT
    public:
        explicit Application(int &argc, char **argv);
        ~Application();

    private:
        void registerMetaTypes();
        void loadPlugins();
        void unloadPlugins();
        void loadFonts();
        void setupView();

        ApplicationDetail *m_detail;
    };

}
