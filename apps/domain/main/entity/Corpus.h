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

#include "EditsCorpusInfo.h"
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

    class Corpus : public QObject, public Entity<CorpusId, corpus::CorpusProperty>, public EditsCorpusInfo {
        Q_OBJECT
    private:
        void setNewCorpus(const Corpus &other);
    protected:
        corpus::CorpusInfoProperty &info() final { return value().infoProperty(); }
        void notifyInfoChanged() final;
    public:
        Corpus() : Corpus(CorpusId(), corpus::CorpusProperty()) { }
        Corpus(const CorpusId& id, const corpus::CorpusProperty &value, QObject *parent = 0)
                : QObject(parent), Entity<CorpusId, corpus::CorpusProperty>(id, value) { }
        Corpus(const Corpus &other, QObject *parent = 0) : Corpus(other.id(), other.value(), parent) { }

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
        void insertPhoneme(const corpus::Pronounce pronounce, const corpus::PhonemeInfoProperty phoneme);
        void deletePhoneme(const corpus::Pronounce pronounce, const corpus::PhonemeInfoProperty phoneme);
    signals:
        /**
         * This signal means that dirty flag may be changed.
         */
        void corpusLoaded();
        void corpusInfoPropertyChanged(const corpus::CorpusInfoProperty);
        void phonemeInserted(const corpus::Pronounce, const corpus::PhonemeInfoProperty);
        void phonemeDeleted(const corpus::Pronounce, const corpus::PhonemeInfoProperty);
    };
}
}

#endif //VSAMPLER_CORPUS_H
