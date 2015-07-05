/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUS_H
#define VSAMPLER_CORPUS_H

#include <QSharedData>
#include <QSharedDataPointer>
#include <QSharedPointer>

#include "value/CorpusProperty.h"
#include "repsoitory/CorpusRepository.h"
#include "service/UtauVoicebankConvertService.h"

#include "Entity.h"
#include "util/Try.h"
#include "UtauVoicebank.h"

namespace vsampler {
namespace domain {

    extern const QSharedPointer<CorpusRepository> DefaultCorpusRepository;
    extern const QSharedPointer<UtauVoicebankConvertService> DefaultUtauVoicebankConvertService;

    class Corpus : public QObject, public Entity<CorpusId, corpus::CorpusProperty> {
        Q_OBJECT
    private:
        bool dirty;
        void setNewCorpus(const Corpus &other);
    public:
        Corpus(QObject *parent = 0) : QObject(parent), Entity<CorpusId, corpus::CorpusProperty>(), dirty(false) { }
        Corpus(const CorpusId& id, const corpus::CorpusProperty &value, QObject *parent = 0)
                : QObject(parent), Entity<CorpusId, corpus::CorpusProperty>(id, value), dirty(false) { }
        Corpus(const Corpus &other) : QObject(other.parent()), Entity<CorpusId, corpus::CorpusProperty>(other), dirty(other.dirty) { }

        bool isDirty() const { return dirty; }
        util::Try<util::Unit> save(
                QSharedPointer<CorpusRepository> repository = DefaultCorpusRepository);
        util::Try<util::Unit> saveAs(
                const CorpusId &newId,
                QSharedPointer<CorpusRepository> repository = DefaultCorpusRepository);
        util::Try<util::Unit> load(
                const CorpusId &id,
                QSharedPointer<CorpusRepository> repository = DefaultCorpusRepository);
        util::Try<util::Unit> loadFrom(
                const UtauVoicebankId &utauVoicebankId,
                const UtauVoicebankConvertService::ConvertOption &option,
                const QSharedPointer<UtauVoicebankConvertService> service = DefaultUtauVoicebankConvertService);
    public slots:
        void setCorpusInfoProperty(const corpus::CorpusInfoProperty corpusInfoProperty);
        void insertPhoneme(const corpus::Pronounce pronounce, const corpus::PhonemeInfoProperty phoneme);
        void deletePhoneme(const corpus::Pronounce pronounce, const corpus::PhonemeInfoProperty phoneme);
    signals:
        /**
         * This signal means that dirty flag may be changed.
         */
        void maybeDirtyChanged(bool isDirty);
        void corpusLoaded();
        void corpusInfoPropertyChanged(const corpus::CorpusInfoProperty);
        void phonemeInserted(const corpus::Pronounce, const corpus::PhonemeInfoProperty);
        void phonemeDeleted(const corpus::Pronounce, const corpus::PhonemeInfoProperty);
    };
}
}



#endif //VSAMPLER_CORPUS_H
