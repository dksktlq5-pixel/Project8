#include "SpartaGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "SpartaGameState.h"

ASpartaGameMode::ASpartaGameMode()
{
    PlayerControllerClass = ASpartaPlayerController::StaticClass();
    DefaultPawnClass = ASpartaCharacter::StaticClass();
    GameStateClass = ASpartaGameState::StaticClass();
}