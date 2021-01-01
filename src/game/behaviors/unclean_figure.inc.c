void bhv_unclean_figure_loop(void) {
    u8 event = o->oBehParams >> 24;

    if (gMarioState->curEvent >= event)
    {
        cur_obj_set_model(MODEL_UNCLEAN_FIGURE);
        o->oMoveAngleYaw = o->oAngleToMario;
        o->oFaceAngleYaw = o->oAngleToMario;
    }
    else
        cur_obj_set_model(MODEL_NONE);
}
