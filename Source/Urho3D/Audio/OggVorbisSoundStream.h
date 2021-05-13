// Copyright (c) 2008-2021 the Urho3D project
// Copyright (c) 2021 проект Dviglo
// Лицензия: MIT

#pragma once

#include "../Audio/SoundStream.h"
#include "../Container/ArrayPtr.h"

namespace Dviglo
{

class Sound;

/// Ogg Vorbis sound stream.
class URHO3D_API OggVorbisSoundStream : public SoundStream
{
public:
    /// Construct from an Ogg Vorbis compressed sound.
    explicit OggVorbisSoundStream(const Sound* sound);
    /// Destruct.
    ~OggVorbisSoundStream() override;

    /// Seek to sample number. Return true on success.
    bool Seek(unsigned sample_number) override;

    /// Produce sound data into destination. Return number of bytes produced. Called by SoundSource from the mixing thread.
    unsigned GetData(signed char* dest, unsigned numBytes) override;

protected:
    /// Decoder state.
    void* decoder_;
    /// Compressed sound data.
    SharedArrayPtr<signed char> data_;
    /// Compressed sound data size in bytes.
    unsigned dataSize_;
};

}
