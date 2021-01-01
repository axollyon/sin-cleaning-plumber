/**
 * Behaviors for bhvPoleGrabbing and bhvGiantPole.
 *
 * bhvPoleGrabbing is a generic behavior used almost anywhere the player can
 * grab onto and climb up another object.
 *
 * bhvGiantPole controls the large pole in Whomp's Fortress and differs from
 * other poles because it spawns a yellow ball that rests at its top.
 */

/**
 * Initialize the hitbox height field for bhvPoleGrabbing.
 */
void bhv_pole_init(void) {
    /**
     * This is equivalent to using `o->oBehParams2ndByte` according to
     * `spawn_objects_from_info`.
     */
    s32 tenthHitboxHeight = o->oBehParams >> 0x10 & 0xFF;
    o->hitboxHeight = tenthHitboxHeight * 10;
}

/**
 * Main loop for bhvGiantPole. It is equivalent to bhv_pole_base_loop() except
 * for the fact that it spawns a yellow sphere at the top of the pole on the
 * first frame.
 */
void bhv_giant_pole_loop(void) {
    struct Object *topBall;
    if (o->oTimer == 0) {
        topBall = spawn_object(o, MODEL_YELLOW_SPHERE, bhvYellowBall);
        topBall->oPosY += o->hitboxHeight + 50.0f;
    }
    bhv_pole_base_loop();
}

void bhv_rope_loop(void) {
    u8 event = o->oBehParams >> 24;
    if (gMarioState->curEvent >= event)
    {
        cur_obj_set_model(MODEL_ROPE);
        bhv_pole_base_loop();
    }
    else
        cur_obj_set_model(MODEL_NONE);
}
