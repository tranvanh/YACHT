#include "GuiLib/Application.h"

class PacmanApplication : public Application {
public:
    PacmanApplication();

protected:
    virtual void installEventHandlers() override;
};
