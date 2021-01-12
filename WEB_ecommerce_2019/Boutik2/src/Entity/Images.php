<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;
use ApiPlatform\Core\Annotation\ApiResource;
/**
 * Images
 *
 * @ORM\Table(name="images")
 * @ORM\Entity
 */
/**
 * ...
 * @ApiResource(
 *     collectionOperations={"get"},
 *     itemOperations={"get"}
 * )
 */
class Images
{
    /**
     * @var int
     *
     * @ORM\Column(name="id", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $id;

    /**
     * @var int|null
     *
     * @ORM\Column(name="id_article", type="integer", nullable=true)
     */
    private $idArticle;

    /**
     * @var string
     *
     * @ORM\Column(name="url", type="string", length=128, nullable=false)
     */
    private $url;

    /**
     * @var int|null
     *
     * @ORM\Column(name="id_user", type="integer", nullable=true)
     */
    private $idUser;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getIdArticle(): ?int
    {
        return $this->idArticle;
    }

    public function setIdArticle(?int $idArticle): self
    {
        $this->idArticle = $idArticle;

        return $this;
    }

    public function getUrl(): ?string
    {
        return $this->url;
    }

    public function setUrl(string $url): self
    {
        $this->url = $url;

        return $this;
    }

    public function getIdUser(): ?int
    {
        return $this->idUser;
    }

    public function setIdUser(?int $idUser): self
    {
        $this->idUser = $idUser;

        return $this;
    }


}
