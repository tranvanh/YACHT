#include "GuiLib/Application.h"

PACMAN_NAMESPACE_BEGIN

class PacmanApplication : public YACHT::Application {
public:
    PacmanApplication();

protected:
    virtual void installEventHandlers() override;
};

PACMAN_NAMESPACE_END
