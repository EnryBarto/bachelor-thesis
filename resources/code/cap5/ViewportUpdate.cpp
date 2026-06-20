// Aggiorna la proiezione se la finestra viene ridimensionata
if (this->windowManager.isFramebufferChanged())
  this->projection->setAspectRatio(
    this->windowManager.getAspectRatio()
  );

// Manipolazione della camera con il tasto sinistro del mouse
if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS
    && !this->guiManager.isPointerUsedByGui()) {

    { ... } // Lettura posizione cursore

    if (isShiftPressed())
      this->moveParallel(deltaX, deltaY);         // Traslazione
    else
      this->rotateTrackball(origin, destination); // Rotazione

    { ... } // Aggiornamento ultima posizione del mouse
}