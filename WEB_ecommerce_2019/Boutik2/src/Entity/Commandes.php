<?php

namespace App\Entity;
use ApiPlatform\Core\Annotation\ApiResource;
use Doctrine\ORM\Mapping as ORM;

/**
 * Commandes
 *
 * @ORM\Table(name="commandes")
 * @ORM\Entity
 */
/**
 * ...
 * @ApiResource(
 *     collectionOperations={"get"},
 *     itemOperations={"get"}
 * )
 */
class Commandes
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
     * @var string
     *
     * @ORM\Column(name="addresse", type="text", length=65535, nullable=false)
     */
    private $addresse;

    /**
     * @var int
     *
     * @ORM\Column(name="post_code", type="integer", nullable=false)
     */
    private $postCode;

    /**
     * @var string
     *
     * @ORM\Column(name="nom", type="string", length=128, nullable=false)
     */
    private $nom;

    /**
     * @var int
     *
     * @ORM\Column(name="id_pays", type="integer", nullable=false)
     */
    private $idPays;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getAddresse(): ?string
    {
        return $this->addresse;
    }

    public function setAddresse(string $addresse): self
    {
        $this->addresse = $addresse;

        return $this;
    }

    public function getPostCode(): ?int
    {
        return $this->postCode;
    }

    public function setPostCode(int $postCode): self
    {
        $this->postCode = $postCode;

        return $this;
    }

    public function getNom(): ?string
    {
        return $this->nom;
    }

    public function setNom(string $nom): self
    {
        $this->nom = $nom;

        return $this;
    }

    public function getIdPays(): ?int
    {
        return $this->idPays;
    }

    public function setIdPays(int $idPays): self
    {
        $this->idPays = $idPays;

        return $this;
    }


}
