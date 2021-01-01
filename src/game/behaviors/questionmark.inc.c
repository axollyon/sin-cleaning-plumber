void bhv_questionmark_loop(void) {
    u8 event = o->oBehParams >> 24;
    u8 autoDisappear = ((o->oBehParams >> 8) & 0xFF) > 0;

    if (!current_mario_room_check(o->oRoom) || (autoDisappear && (event != gMarioState->curEvent)))
    {
        cur_obj_set_model(MODEL_NONE);
        o->oQMarkInteractable = FALSE;
    }
    else if (event == gMarioState->curEvent)
    {
        cur_obj_set_model(MODEL_QUESTIONMARK);
        o->oQMarkInteractable = TRUE;
    }

    if (o->oQMarkInteractable)
    {
        o->oIntangibleTimer = 0;
        o->oMoveAngleYaw = o->oAngleToMario;
    }
    else
        o->oIntangibleTimer = -1;
    o->oInteractStatus = 0;
}
