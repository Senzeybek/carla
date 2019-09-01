#pragma once

#include <vector>
#include <memory>

#include "carla/Memory.h"
#include "carla/client/Actor.h"

#include "Messenger.h"
#include "SimpleWaypoint.h"

namespace traffic_manager {

    /// Data types

    struct LocalizationToPlannerData {
        carla::SharedPtr<carla::client::Actor> actor;
        float deviation;
        // bool approaching_true_junction;
    };

    struct PlannerToControlData {
        carla::SharedPtr<carla::client::Actor> actor;
        float throttle;
        float brake;
        float steer;
    };

    /// Data frame types

    typedef std::vector<LocalizationToPlannerData> LocalizationToPlannerFrame;
    typedef std::vector<PlannerToControlData> PlannerToControlFrame;

    /// Messenger types

    typedef Messenger<LocalizationToPlannerFrame*> LocalizationToPlannerMessenger;
    typedef Messenger<PlannerToControlFrame*> PlannerToControlMessenger;
}