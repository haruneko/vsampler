/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "value/json/CorpusPropertyJson.h"
#include "value/CorpusProperty.h"
#include "repsoitory/impl/JsonFileCorpusRepository.h"

#include "Corpus.h"

const QSharedPointer<vsampler::domain::CorpusRepository> vsampler::domain::DefaultCorpusRepository =
        QSharedPointer<vsampler::domain::CorpusRepository>(new vsampler::domain::impl::JsonFileCorpusRepository);

vsampler::util::Try<vsampler::util::Unit> vsampler::domain::Corpus::save(QSharedPointer<CorpusRepository> repository) {
    return saveAs(id(), repository);
}

vsampler::util::Try<vsampler::util::Unit> vsampler::domain::Corpus::saveAs(
        const CorpusId &newId,
        QSharedPointer<CorpusRepository> repository) {
    return repository->upsert(Corpus(newId, this->value()))
            .map<vsampler::util::Unit>([this, newId](const vsampler::util::Unit &u) -> vsampler::util::Unit{
                this->setId(newId);
                return u;
            });
}

vsampler::util::Try<vsampler::util::Unit> vsampler::domain::Corpus::load(
        const CorpusId &id,
        QSharedPointer<CorpusRepository> repository) {
    return repository->fetchBy(id).map<vsampler::util::Unit>([this](const Corpus &c) -> vsampler::util::Unit {
        setNewCorpus(c);
        return vsampler::util::Unit();
    });
}

vsampler::util::Try<vsampler::util::Unit> vsampler::domain::Corpus::loadFrom(
        const UtauVoicebankId &utauVoicebankId,
        const UtauVoicebankConvertService::ConvertOption &option,
        const QSharedPointer<UtauVoicebankConvertService> service) {
    return service->convert(utauVoicebankId, option)
            .map<vsampler::util::Unit>([this, utauVoicebankId](const vsampler::corpus::CorpusProperty &prop) -> vsampler::util::Unit {
                setNewCorpus(Corpus(utauVoicebankId, prop));
                return vsampler::util::Unit();
            });
}

void vsampler::domain::Corpus::setNewCorpus(const Corpus &other) {
    this->setId(other.id());
    this->setValue(other.value());
    emit(this->corpusLoaded());
}

void vsampler::domain::Corpus::deletePhoneme(
        const corpus::Pronounce pronounce,
        const corpus::PhonemeInfoProperty phoneme) {
    this->d->value.phonemeSet()[pronounce].remove(phoneme);
    emit(phonemeDeleted(pronounce, phoneme));
}

void vsampler::domain::Corpus::insertPhoneme(
        const corpus::Pronounce pronounce,
        const corpus::PhonemeInfoProperty phoneme) {
    this->d->value.phonemeSet()[pronounce].insert(phoneme);
    emit(phonemeInserted(pronounce, phoneme));
}

void vsampler::domain::Corpus::notifyInfoChanged() {
    emit(corpusInfoPropertyChanged(value().infoProperty()));
}
