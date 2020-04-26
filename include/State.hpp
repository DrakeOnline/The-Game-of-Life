#pragma once

namespace DrakeOnline {

    class State {
        public:
            // =====================PUBLIC METHODS======================
            // Start state
            virtual void Initialize()       = 0;
            // Handle events
            virtual void HandleInput()      = 0;
            virtual void Update(float)      = 0;
            virtual void Draw(float)        = 0;
            // State manipulation
            virtual void Pause() {};
            virtual void Resume() {};
    };
}
