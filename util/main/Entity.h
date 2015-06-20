/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_ENTITY_H
#define VSAMPLER_ENTITY_H

#include <QSharedData>
#include <QSharedDataPointer>

namespace vsampler {
    template <class Identifier, class Value> class Entity {
        class EntityData final : public QSharedData {
        public:
            EntityData(const Identifier &id, const Value &value) : id(id), value(value) { }
            Identifier id;
            Value value;
        };
        QSharedDataPointer<EntityData> d;
    public:
        Entity() : d() { }
        Entity(const Identifier &id, const Value &value) : d(new EntityData(id, value)) { }
        Entity(const Entity<Identifier, Value> &other) : Entity(other.id(), other.value()) { }
        Entity<Identifier, Value> &operator =(const Entity<Identifier, Value> &other) { this->d = other.d; return *this; }

        virtual ~Entity() { }

        const Identifier &id() const { return d->id; }
        Identifier &id() { return d->id; }

        const Value &value() const { return d->value; }
        Value &value() { return d->value; }

        bool operator ==(const Entity<Identifier, Value> &right) {
            return id() == right.id();
        }
    };

}


#endif //VSAMPLER_ENTITY_H
