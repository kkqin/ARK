﻿/*
* This source file is part of ARK
* For the latest info, see https://github.com/QuadHex
*
* Copyright (c) 2013-2018 QuadHex authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#pragma once

#include "SDK/Core/AFPlatform.hpp"
#include "SDK/Core/AFMacros.hpp"

#pragma pack(push, 1)

namespace ark
{

    enum AFNetEventType
    {
        NONE = 0,
        CONNECTED = 1,
        DISCONNECTED = 2,
        RECV_DATA = 3,
    };

    class AFNetEvent
    {
    public:
        AFNetEvent() = default;

        ~AFNetEvent()
        {
        }

        static AFNetEvent* AllocEvent()
        {
            return ARK_NEW AFNetEvent();
        }

        static void Release(AFNetEvent*& event)
        {
            ARK_DELETE(event);
        }

        AFNetEventType type_{ AFNetEventType::NONE };
        int64_t id_{0};
        std::string ip_{};
        int bus_id_{ 0 };
    };

}

#pragma pack(pop)