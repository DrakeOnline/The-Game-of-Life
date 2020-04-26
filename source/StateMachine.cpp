
#include "./../include/StateMachine.hpp"


namespace DrakeOnline {

    // =====================PUBLIC METHODS======================
    void StateMachine::AddState(StateRef newState, bool isReplacing) {
        this->_isAdding     = true;
        this->_isReplacing  = isReplacing;
        this->_newState     = std::move(newState);
    }

    void StateMachine::RemoveState() { this->_isRemoving = true; }

    void StateMachine::ProcessStateChanges() {
        // For removing states
        if(this->_isRemoving && !this->_states.empty()) {
            this->_states.pop();

            // Resume state after top one gets popped
            if (!this->_states.empty()) { this->_states.top()->Resume(); }

            // Reset removing flag
            this->_isRemoving = false;
        }

        // For adding states
        if(this->_isAdding) {

            if(!this->_states.empty()) {
                // If it's replacing, pop top state
                if(this->_isReplacing) { this->_states.pop(); }
                // If it's not replacing, pause top state
                else { this->_states.top()->Pause(); }
            }

            this->_states.push(std::move(this->_newState));
            this->_states.top()->Initialize();
            this->_isAdding = false;


        }
    }

    StateRef& StateMachine::GetActiveState() { return this->_states.top(); }

}
