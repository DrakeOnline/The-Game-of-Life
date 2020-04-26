#pragma once

#include <memory>
#include <stack>
#include "State.hpp"


namespace DrakeOnline {

    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
        public:
            // ======================CONSTRUCTORS=======================
            StateMachine() {}
            ~StateMachine() {}
            // =====================PUBLIC METHODS======================
            void        AddState(StateRef, bool = true);
            void        RemoveState();
            void        ProcessStateChanges();
            StateRef&   GetActiveState();
        private:
            // ====================PRIVATE VARIABLES====================
            std::stack<StateRef>    _states;
            StateRef                _newState;
            bool                    _isRemoving;
            bool                    _isAdding;
            bool                    _isReplacing;
    };

}
