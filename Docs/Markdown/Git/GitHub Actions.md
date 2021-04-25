# GitHub Actions

GitHub Actions - это скрипты, которые выполняются на сервере GitHub.

Официальная документация: <https://docs.github.com/actions>.

Конфиги располагаются в папке [.github/workflows](https://github.com/Dviglo/Dviglo/tree/master/.github/workflows).
Формат файлов - [YAML](https://ru.wikipedia.org/wiki/YAML).

# Отправка коммитов в другой репозиторий

Чтобы скрипт мог отправлять коммиты в другие репозитории, нужен токен, предоставляющий такие права.
В конфиге <https://github.com/Dviglo/GameDevDocs/blob/master/.github/workflows/convert.yml> такой токен - `DVIGLO_SITE_TOKEN`.

Для создания токена:
1) [Ваши Settings > Developer settings > Personal access tokens](https://github.com/settings/tokens)
2) Нажать кнопку `Generate new token`
3) Ввести название токена и поставить галочку напротив `repo` (все подпункты тоже выделятся)
4) Нажать кнопку `Generate token`
5) Скопировать показанный токен, так как его больше невозможно будет посмотреть. При потере токена возможно только сгенерировать новый

Для использования токена:
1) `Settings` репозитория, в котором должен выполняться скрипт > `Secrets`
2) Нажать кнопку `New repository secret`
3) Ввести название токена и сам токен
4) Нажать кнопку `Add secret`

**Теги: GitHub, сайт Dviglo**
